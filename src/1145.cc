#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
    int id;
};

int max_count = 0;
vector<int> best_s;

bool is_collinear(const Point &pi, const Point &pj, const Point &pk)
{
    long long val = (pj.x - pi.x) * (pk.y - pi.y) - (pk.x - pi.x) * (pj.y - pi.y);
    return val == 0;
}

bool is_better(const vector<int> &current_s)
{
    if (best_s.empty())
        return true;
    if (current_s[0] < best_s[0])
        return true;
    if (current_s[0] > best_s[0])
        return false;

    return current_s[1] < best_s[1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<Point> points(N);
    for(int i = 0; i < N; ++i){
        cin >> points[i].x >> points[i].y;
        points[i].id = i;
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            vector<int> current_s;

            for (int k = 0; k < N; ++k)
            {
                if (k == i || k == j || is_collinear(points[i], points[j], points[k]))
                    current_s.push_back(points[k].id);
            }

            int current_count = current_s.size();
            sort(current_s.begin(), current_s.end());

            if (current_count > max_count)
            {
                max_count = current_count;
                best_s = current_s;
            }
            else if (current_count == max_count)
            {
                if (is_better(current_s))
                {
                    best_s = current_s;
                }
            }
        }
    }
    cout << best_s[0] << " " << best_s[1] << endl;
    return 0;
}