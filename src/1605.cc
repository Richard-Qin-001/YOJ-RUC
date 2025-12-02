#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N;
    cin >> N;
    if(N % 2 != 0){
        cout << "YES" << endl;
        return;
    }
    if(N % 4 == 0){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) solve();
    return 0;
}