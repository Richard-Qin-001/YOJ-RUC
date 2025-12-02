#include <bits/stdc++.h>
using namespace std;

vector<bool> is_prime;
vector<int> primes;

void generate_prime(int n){
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 0; i <= n; ++i){
        if(is_prime[i])primes[i]++;
        for(auto&prime:primes){
            if(i * prime > n)break;
            is_prime[i * prime] = false;
            if(i % prime == 0)break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    generate_prime(n * n);
    vector<vector<int>> matrix;
}