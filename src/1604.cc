#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

void solve(){
    ull n;
    cin >> n;
    if(n == 1) {
        cout << 1 << endl;
        return;
    }
    while (n > 1){
        if(n % 2 == 1) {
            cout << 2 << endl;
            return;
        }
        n /= 2;
    }
    cout << 1 << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)solve();
    return 0;
}