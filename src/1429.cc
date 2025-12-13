#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 998244353;
constexpr int INV2 = 499122177;

struct Node
{
    ll g;
    int L, R;
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Node> last;
    ll ans = 0;

    for(int i = 1; i <= n; ++i){
        ll val;
        cin >> val;

        for(auto&node : last)node.g = gcd(node.g, val);
        last.push_back({val, i, i});

        vector<Node> curr;
        for(auto&node : last)
        {
            if(curr.empty() || node.g != curr.back().g)
                curr.push_back(node);
            else curr.back().R = node.R;
        }

        ll current_i_sum = 0;

        for(auto&node:curr)
        {
            ll L = node.L, R = node.R;
            ll s_l = (L + R) % MOD * ((R - L + 1) % MOD) % MOD * INV2 % MOD;
            ll term  = (s_l * i % MOD) * (node.g % MOD) % MOD;
            current_i_sum = (current_i_sum + term) % MOD;
        }
        ans = (ans + current_i_sum) % MOD;
        last = curr;
    }
    cout << ans << endl;
    return 0;
}