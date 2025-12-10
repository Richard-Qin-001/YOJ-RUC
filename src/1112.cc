#include <bits/stdc++.h>
using namespace std;

int main(){
    int m ,n;
    cin >> m >> n;
    vector<pair<int, int>> games(n);
    for(int i = 0; i < n; ++i)cin >> games[i].first;
    for (int i = 0; i < n; ++i)cin >> games[i].second;
    sort(games.begin(), games.end(), [](const pair<int, int>&a, const pair<int, int>&b){
        return a.second > b.second;
    });
    vector<bool> used(n + 1, false);
    for(int i = 0; i < n; ++i){
        int ti = games[i].first;
        int j = ti;
        while (j >= 1)
        {
            if(!used[j]){
                used[j] = true;
                break;
            }
            j--;
        }
        if(j == 0)m -= games[i].second;
    }
    cout << m << endl;
    return 0;
}