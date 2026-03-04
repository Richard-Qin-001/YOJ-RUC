#include <bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> c(n + 1);
    vector<long long> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    vector<long long> S(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        S[i] = S[i - 1] + v[i];
    }

    vector<long long> dp(n + 1, 0);
    // max_val[x] 记录花色为 x 的历史最高 (dp[j-1] - S[j-1])
    vector<long long> max_val(k + 1, LONG_LONG_MIN);

    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];

        if (max_val[c[i]] != LONG_LONG_MIN)
        {
            dp[i] = max(dp[i], max_val[c[i]] + S[i]);
        }
        max_val[c[i]] = max(max_val[c[i]], dp[i - 1] - S[i - 1]);
    }

    cout << dp[n] << "\n";

    return 0;
}