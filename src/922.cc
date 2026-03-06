#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i)cin >> a[i];
    ll total = accumulate(a.begin(), a.end(), 0ll);
    ll average = total / n;
    vector<ll> prefix(n);
    for(int i = 0; i < n - 1; ++i){
        prefix[i + 1] = prefix[i] + a[i+1]-average;
    }
    sort(prefix.begin(), prefix.end());
    ll median = prefix[n / 2];
    ull min_cost = 0;
    for (int i = 0; i < n; ++i){
        min_cost += std::abs(prefix[i]-median);
    }
    cout << min_cost << endl;
    return 0;
}