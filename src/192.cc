#include <iostream>

using namespace std;

bool isPrime(int n){
    if (n <= 1) return false;
    if (n == 2) return true;
    for(int i = 3; i * i <= n; i++)if(n%i == 0) return false;
    return true;
}

void solve(){
    int n;
    cin >> n;
    int a, b;
    for(a = 1; a < n; a++){
        b = n - a;
        if(a % 2 != 0 && b % 2 != 0 && isPrime(a) && isPrime(b)) break;
    }
    cout << n << "=" << a << "+" << b << endl;
}
int main(){solve(); return 0;}