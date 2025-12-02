#include <bits/stdc++.h>
using namespace std;

vector<bool> is_prime;
vector<int> primes;

void generate_primes(int n){
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++){
        if(is_prime[i])primes.push_back(i);
        for(auto&p:primes){
            if(i * p > n)break;
            is_prime[i * p] = false;
            if(i % p == 0) break;
        }
    }
}

bool is_huiwen(int n){
    string num = to_string(n);
    int start = 0, end = num.length() - 1;
    while (true){
        if(start >= end) break;
        if(num[start] != num[end])return false;
        start++, end--;
    }
    return true;
}

int digit_sum(int n){
    int result = 0;
    string num = to_string(n);
    int len = num.length();
    for(int i = 0; i < len ;i ++){
        result += num[i] - '0';
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    generate_primes(n);
    vector<vector<int>> solutions;
    vector<int> solution;
    for(auto&p:primes){
        if(p >= m && p <= n&&is_huiwen(p)){
            solution = {p, digit_sum(p)};
            solutions.push_back(solution);
        }
    }
    if(solutions.size() == 0){
        cout << "0 0" << endl;
        return 0;
    }
    sort(solutions.begin(), solutions.end(), [](const vector<int>&a, const vector<int>&b){
        if(a[1] != b[1])return a[1] > b[1];
        return a[0] < b[0];
    });
    cout << solutions[0][0] << " " << solutions[0][1] << endl;
    return 0;
}