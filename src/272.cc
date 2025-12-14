#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 1e6;

vector<bool>is_prime(MAX_N + 1, true);
vector<int>primes;

void generate_primes(){
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= MAX_N; ++i){
        if(is_prime[i])primes.push_back(i);
        for(auto&p:primes){
            if(p * i > MAX_N)break;
            is_prime[p * i] = false;
            if (i % p == 0)break;
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> sol1, sol2;
    int cnt = 0;
    for(auto&p:primes){
        if(p > n/2)break;
        int tmp = n - p;
        if(is_prime[tmp]){
            if(sol1.empty()){
                sol1 = {p, tmp};
            }
            sol2 = {p, tmp};
            cnt++;
        }
    }
    cout << sol1[0] << "+" << sol1[1] << " " << sol2[0] << "+" << sol2[1] << " " << cnt << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    generate_primes();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        solve();
    }
    return 0;
}