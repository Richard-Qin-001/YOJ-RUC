#include <bits/stdc++.h>
using namespace std;

struct Circle
{
    double x, y, r;
};
struct Point
{
    double x, y;
};

int n, m;
double R_max;
vector<Circle> obstacles;
vector<Point> targets;
double best_x, best_y;
int max_points = 0;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_real_distribution<double> dist_real(-1.0, 1.0);
uniform_real_distribution<double> dist_prob(0.0, 1.0);

double get_radius(double x, double y)
{
    double r = R_max;
    for (int i = 0; i < n; ++i)
    {
        double dist = sqrt((x - obstacles[i].x) * (x - obstacles[i].x) +
                           (y - obstacles[i].y) * (y - obstacles[i].y));
        r = min(r, max(0.0, dist - obstacles[i].r));
    }
    return r;
}

int count_points(double x, double y)
{
    double r = get_radius(x, y);
    if (r <= 1e-9)
        return 0;

    double r_sq = (r + 1e-8) * (r + 1e-8);
    int cnt = 0;
    for (int i = 0; i < m; ++i)
    {
        double dx = x - targets[i].x, dy = y - targets[i].y;
        if (dx * dx + dy * dy <= r_sq)
            cnt++;
    }
    return cnt;
}

void sa(double sx, double sy)
{
    double t = 100000;
    double curr_x = sx, curr_y = sy;
    int curr_ans = count_points(curr_x, curr_y);

    if (curr_ans > max_points)
    {
        max_points = curr_ans;
        best_x = curr_x;
        best_y = curr_y;
    }

    while (t > 1e-4)
    {
        double next_x = curr_x + dist_real(rng) * t;
        double next_y = curr_y + dist_real(rng) * t;

        int next_ans = count_points(next_x, next_y);
        int delta = next_ans - curr_ans;

        if (delta > 0)
        {
            curr_x = next_x;
            curr_y = next_y;
            curr_ans = next_ans;
            if (curr_ans > max_points)
            {
                max_points = curr_ans;
                best_x = curr_x;
                best_y = curr_y;
            }
        }
        else if (exp(delta / t) > dist_prob(rng))
        {
            curr_x = next_x;
            curr_y = next_y;
            curr_ans = next_ans;
        }
        t *= 0.996;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> R_max;
    obstacles.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> obstacles[i].x >> obstacles[i].y >> obstacles[i].r;

    targets.resize(m);
    double sum_x = 0, sum_y = 0;
    for (int i = 0; i < m; ++i)
    {
        cin >> targets[i].x >> targets[i].y;
        sum_x += targets[i].x;
        sum_y += targets[i].y;
    }

    if (m > 0)
    {
        sa(sum_x / m, sum_y / m);

        for (int i = 0; i < 30; i++)
        {
            int id = rng() % m;
            sa(targets[id].x, targets[id].y);
        }
    }

    cout << max_points << "\n";
    return 0;
}