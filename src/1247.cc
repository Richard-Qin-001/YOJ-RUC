#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> happiness(m + 1, 0);
    for(int i = 1; i <= m; ++i)cin >> happiness[i];
    vector<ll> dp(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        ll  max_happiness = 0L;
        int max_k = min(i, m);
        for(int k = 1; k <= max_k; ++k){
            ll current_happiness = dp[i - k] + happiness[k];
            max_happiness = max(max_happiness, current_happiness);
        }
        dp[i] = max_happiness;
    }
    cout << dp[n] << endl;
    return 0;
}