#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> judge_array(n);
    for(auto&c:judge_array)cin >> c;
    auto max_idx = max_element(judge_array.begin(), judge_array.end());
    int max = *max_idx;
    vector<bool> is_prime(max + 1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= max; i++){
        if(is_prime[i])primes.push_back(i);
        for(auto&prime:primes){
            if(i * prime > max)break;
            is_prime[i * prime] = false;
            if(i % prime == 0)break;
        }
    }
    for(int i = 0; i < n; ++i){
        if(is_prime[judge_array[i]])cout << "YES";
        else cout << "NO";
        if(i != n - 1)cout << " ";
    }
    return 0;
}