#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pair<int, string>> circle(n);
    for(int i = 0; i < n; ++i){
        cin >> circle[i].first >> circle[i].second;
    }
    int ai = 0, si = 0;
    int sign = 1, pos = 0;
    for(int i = 0; i < m; ++i){
        cin >> ai >> si;
        sign = -1;
        if(circle[pos].first == 1)sign *= -1;
        if(ai == 1)sign *= -1;
        pos = (pos + sign * si) % n;
        while (pos < 0)
            pos+=n;
        
    }
    cout << circle[pos].second << endl;
    return 0;
}