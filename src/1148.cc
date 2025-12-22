#include <bits/stdc++.h>
using namespace std;

int n, k, results = 0;
vector<vector<vector<int>>> memo;

int dfs(int last, int sum, int cnt){
    if(cnt == k){
        if(n - sum >= last){
            return 1;
        }
        return 0;
    }
    if(memo[last][sum][cnt] != -1)return memo[last][sum][cnt];
    int res = 0;
    for(int i = last; sum + i * (k - cnt + 1) <= n; ++i){
        res += dfs(i, sum + i, cnt + 1);
    }
    return memo[last][sum][cnt] = res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    memo.assign(n + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
    cout << dfs(1, 0, 1) << endl;
    return 0;
    
}