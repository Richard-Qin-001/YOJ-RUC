#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Point
{
    int x, y;
    int type;
    ll distance;
};

ll calculate_distance(const Point&p, const Point&q){
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, k;
    cin >> m >> k;
    vector<Point> dataset;
    dataset.reserve(1000000);
    Point p;
    for(int i = 1; i <= m; ++i){
        int n;
        cin >> n;
        for(int j = 0; j < n; ++j){
            cin >> p.x >> p.y;
            p.type = i;
            dataset.emplace_back(p);
        }
    }
    Point target;
    cin >> target.x >> target.y;
    for(auto&p:dataset)p.distance = calculate_distance(p, target);
    sort(dataset.begin(), dataset.end(), [](const Point&p, const Point&q){
        if(p.distance != q.distance)return p.distance < q.distance;
        return p.type < q.type;
    });
    int sz = dataset.size();
    vector<int> countMap(m + 1, 0);
    for(int i = 0; i < sz && i < k; ++i)countMap[dataset[i].type]++;
    int i = k;
    while (true)
    {
        if(dataset[i].distance == dataset[i-1].distance)countMap[dataset[i].type]++;
        else break;
        ++i;
    }
    
    int final_type = 0, total = 0;
    for(int i = 1; i <= m; ++i){
        if(countMap[i] > total){
            total = countMap[i];
            final_type = i;
        }
    }
    cout << final_type << endl;

}