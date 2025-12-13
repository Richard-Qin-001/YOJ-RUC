#include <bits/stdc++.h>
using namespace std;

struct Point{
    double x, y;
};

double dist_sq(Point a, Point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

Point get_circle_center(Point a, Point b, Point c)
{
    double a1 = b.x - a.x, b1 = b.y - a.y, c1 = (a1 * a1 + b1 * b1) / 2.0;
    double a2 = c.x - a.x, b2 = c.y - a.y, c2 = (a2 * a2 + b2 * b2) / 2.0;
    double d = a1 * b2 - a2 * b1;
    return {a.x + (c1 * b2 - c2 * b1) / d, a.y + (a1 * c2 - a2 * c1) / d};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Point> p(n);
    for(int i = 0; i < n; ++i)cin >> p[i].x >> p[i].y;

    random_shuffle(p.begin(), p.end());

    Point o = p[0];
    double r_sq = 0;

    for(int i = 0; i < n; ++i){
        if (dist_sq(o, p[i]) > r_sq + 1e-9){
            o = p[i], r_sq = 0;
            for(int j = 0; j < i; j++){
                if (dist_sq(o, p[j]) > r_sq + 1e-9) {
                    o = {(p[i].x + p[j].x) / 2.0, (p[i].y + p[j].y) / 2.0};
                    r_sq = dist_sq(o, p[i]);
                    for (int k = 0; k < j; k++) {
                        if (dist_sq(o, p[k]) > r_sq + 1e-9) {
                            o = get_circle_center(p[i], p[j], p[k]);
                            r_sq = dist_sq(o, p[i]);
                        }
                    }
                }
            }
        }
    }
    cout << fixed << setprecision(2) << o.x << " " << o.y << " " << sqrt(r_sq) << endl;
    return 0;
}