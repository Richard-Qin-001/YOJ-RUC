#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Point{
    ll x, y;
};

ll calculate_distance(const Point&a, const Point&b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

ll solve(int left, int right, const vector<Point>&pts){
    if(left +1 >= right){
        if(left == right)return 8e18;
        return calculate_distance(pts[left], pts[right]);
    }

    int mid = left + (right - left) / 2;
    ll midX = pts[mid].x;

    ll d2 = min(solve(left, mid, pts), solve(mid + 1, right, pts));
    vector<Point> strip;
    for (int i = left; i <= right; i++){
        if ((pts[i].x - midX) * (pts[i].x - midX) < d2){
            strip.push_back(pts[i]);
        }
    }
    sort(strip.begin(), strip.end(), [](const Point&p, const Point&q){
        if(p.y!=q.y)return p.y < q.y;
        return p.x < q.x;
    });

    int sz = strip.size();
    for(int i = 0; i < sz; ++i){
        for(int j = i+1;j < sz; ++j){
            if ((strip[j].y - strip[i].y) * (strip[j].y - strip[i].y) >= d2)break;
            d2 = min(d2, calculate_distance(strip[i], strip[j]));
        }
    }
    return d2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Point> pts(n);
    for(int i = 0; i < n; ++i)cin >> pts[i].x >> pts[i].y;
    sort(pts.begin(), pts.end(), [](const Point&a, const Point&b){
        if(a.x != b.x)return a.x < b.x;
        return a.y < b.y;
    });
    cout << solve(0, n - 1, pts) << endl;

    return 0;

}