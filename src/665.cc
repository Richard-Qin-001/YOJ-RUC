#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

bool isPrime(ll n){
    if (n == 1) return false;
    if (n == 2) return true;
    for(ll i = 2; i * i <= n; i++)if(n % i == 0) return false;
    return true;
}

bool process(ll X){
    int count = 0;
    for(ll i = 1; i * i <= X; i++){
        if(X % i == 0)if(isPrime(i))if(isPrime(X / i)){
            cout << i <<  ' ' << X/i << endl;
            for(ll a = 0; a * a <= X; a++)for(ll b = 0; b * b <= X; b++)for(ll c = 0; c* c <= X; c++)for(ll d = 0; d <= X; d++)if(a * a + b * b + c * c + d * d == X){if(a != 0)count++; if(b != 0)count++; if(c != 0) count++; if(d != 0)count++; cout << count << endl; return true;}
        }
    }
    return false;
}

void solve(){
    ll N;
    cin >> N;
    ll X = N+1;
    while (!process(X)) X++;
    {
        
    }
}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}