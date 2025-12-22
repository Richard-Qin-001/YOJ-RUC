#include <bits/stdc++.h>
using namespace std;

int n, k, result = 0;

void dfs(int last, int sum, int cnt){
    if(cnt == k){
        if(n - sum >= last)result++;
        return;
    }
    for(int i = last; sum + i * (k - cnt + 1) <= n; ++i){
        dfs(i, sum + i, cnt + 1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    dfs(1, 0, 1);
    cout << result << endl;
    return 0;
}