#include <iostream>

using namespace std;
using ll = long long;
int gcd(int x, int y){
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

void solve(){
    int a, b;
    cin >> a >> b;
    ll num = (ll)a / gcd(a, b) * b;
    cout << num;
}
int main(){solve(); return 0;}