#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> parks(4, vector<int>(n, 0));
    for(int i = 0; i < 4; ++i)for(int j = 0; j < n; ++j)cin >> parks[i][j];
    int global_min = 1e9, current_min = 0;
    vector<vector<int>> solutions;
    for(int i = 0; i < n; ++i){
        int left = round(parks[1][i] + ((double)parks[3][i] / 10.0) * (double)parks[2][i]);
        if(left > 0)solutions.push_back({i + 1, parks[0][i]});
    }
    if(solutions.size() == 0){
        cout << 0 << endl;
        return 0;
    }
    sort(solutions.begin(), solutions.end(), [](const vector<int>&a, const vector<int>&b){return a[1] < b[1];});
    cout << solutions[0][0] << endl;
    return 0;
}