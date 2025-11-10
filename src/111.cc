#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

ll power(ll base, ll exp){
    ll result = 1;
    for(int i = 0; i < exp; i++) result *= base;
    return result;
}

void solve(ll n){
    const int MAX_M = 9;
    for(int m = MAX_M; m >= 2; m--){
        ll P = power(m ,m);
        if (P > m + n -1) continue;
        ll numerator = n + m - 1;
        

    }
    cout << "no solution" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    while ((cin >> n) && n != 0) solve(n);
    {
        return 0;
    }
}