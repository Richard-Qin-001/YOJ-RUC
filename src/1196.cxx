#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
ll ans1 = 0, ans2 = 0;

ll getValue(const vector<int>&p, int l, int r){
    ll res = 0;
    for(int i = l; i <= r; ++i){
        res = res * 10 + p[i];
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<int>p(m);
    for(int i = 0; i < m; ++i)p[i] = i + 1;
    do
    {
        for(int i = 0; i <= m - 3; ++i){
            ll a = getValue(p, 0, i);
            for(int j = i + 1; j <= m  -2; ++j){
                ll b = getValue(p, i + 1, j);
                ll c = getValue(p, j + 1, m - 1);

                if (b % c == 0 && a + b / c == n)ans1++;
                if (n >= a && b % c == n - a && c > n - a)ans2++;
            }
        }
    } while (next_permutation(p.begin(), p.end()));

    cout << ans1 << " " << ans2 << endl;
    return 0;
}