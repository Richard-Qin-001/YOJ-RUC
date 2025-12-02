#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
int n;
vector<bool> is_prime;
vector<int> primes;

void generate_prime(int n){
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++){
        if(is_prime[i])primes.push_back(i);
        int s = primes.size();
        for(int j = 0; j < s && i * primes[j] <= n; j++){
            is_prime[i * primes[j]] = false;
            if(i % primes[j] == 0)break;
        }
    }
}

int count_prime_powers(int p){
    int count = 1;
    ll power = p;
    while (power <= n){
        count++;
        if(power > n / p)break;
        power *= p;
    }
    return count;
}

void solve(){
    cin >> n;
    generate_prime(n);
    ll total_count = 1;
    for(auto&p:primes){
        int count = count_prime_powers(p);
        total_count = (total_count * count) % MOD;
    }
    cout << total_count << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}