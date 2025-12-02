#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

vector<int> decomposition(32, 0);

void solve(){
    ull n;
    cin >> n;
    if(n % 4 == 0){
        cout << "NO" << endl;
        return;
    }
    for(int i = 0; i < 32; ++i){
        decomposition[i] = n >> i & 1;
    }
    for (int i = 1; i < 32; ++i) {
        if (decomposition[i] == 0 && decomposition[i - 1] == 1) {
            decomposition[i] = 1;
            decomposition[i - 1] = -1;
        }
    }
    cout << "YES" << endl;
    for(int i = 31; i >= 0; i--){
        cout << decomposition[i];
        if(i % 8 == 0) cout << endl;
        else cout << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)solve();
    return 0;
}