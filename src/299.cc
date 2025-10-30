#include <iostream>
#include <map>

using namespace std;

bool isPrime(int a){
    if (a == 1) return false;
    if (a == 2) return true;
    for (int i = 3; i * i < a; i++)if(a % i == 0) return false;
    return true;
}

map<int, int> factors;

void process(int n){
    if (n <= 1) return;
    int n_new = n;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0 && isPrime(i)){
            factors[i]++;
            n_new = n / i;
            break;
        }
    }
    if(n_new == n){
        factors[n_new]++;
        return;
    }
    process(n_new);
}

void solve(){
    int n;
    cin >> n;
    process(n);
    for(auto&p:factors)cout << p.first << ":" << p.second << endl;
}

int main(){solve(); return 0;}