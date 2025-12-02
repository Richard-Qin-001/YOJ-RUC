#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int n1 = a * d + c * b, n2 = b * d, g = gcd(n1, n2);
    n1 = n1 / g, n2 = n2 / g;
    cout << n1 << "/" << n2 << endl;
}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}