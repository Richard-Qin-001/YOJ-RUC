#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll combinations(ll n, ll k) {
    if (k < 0 || k > n){
        return 0;
    }
    if (k == 0 || k == n){
        return 1;
    }
    if (k > n / 2){
        k = n - k;
    }
    ll res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    ll total_ans = 0;

    for (int i = 0; i < (1 << n); ++i) {
        int cnt = 0;
        int curr_m = m;

        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                cnt++;
                curr_m -= (b[j] + 1);
            }
        }

        if (curr_m < 0) {
            continue;
        }

        ll ways = combinations(curr_m + n - 1, n - 1);

        if (cnt % 2 == 1) {
            total_ans -= ways;
        } else {
           total_ans += ways; 
        }
    }
    cout << total_ans << endl;
    return 0;
}