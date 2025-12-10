#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 1e5;
vector<bool> is_prime(MAX_N + 1, true);
vector<ll> primes;

void generate_primes(){
    is_prime[0] = is_prime[1] = false;
    for(ll i = 2; i <= MAX_N; ++i){
        if(is_prime[i])primes.push_back(i);
        for(auto&p:primes){
            if(i * p > MAX_N)break;
            is_prime[i * p] = false;
            if(i % p == 0)break;
        }
    }
}

ll power(ll base, ll exp){
    ll res = 1;
    while (exp > 0)
    {
        if(exp & 1) res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}

void solve(){
    ll n, k;
    cin >> n >> k;
    unordered_map<ll, ll> factors;
    for(auto&p:primes){
        if (n == 1)
            break;
        if(n % p == 0){
            while (n % p == 0)
            {
                factors[p]++;
                n /= p;
            }
        }
    }
    if (n > 1)
    {
        factors[n] = 1;
    }
    ll result = 1;
    for(auto&f:factors){
        if(f.second >= k){
            result = result * power(f.first, f.second);
        }
    }
    cout << result << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    generate_primes();
    for(int i = 0; i < q; ++i){
        solve();
    }
    return 0;
}