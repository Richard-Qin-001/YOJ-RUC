#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<ll> coins(n), moves(m), best;
    for(auto&c:coins) cin >> c;
    for(auto&moven:moves) cin >> moven;
    for(int i = 0; i < n; i++){
        int index = i;
        ll total_coins = 0;
        for(int j = 0; j < m; j++){
            index = (index + moves[j]) % n;
            total_coins += coins[(index)];
        }
        if (best.empty()){
            best = {i, total_coins};
        }
        else if (total_coins > best[1]){
            best = {i, total_coins};
        }
        total_coins = 0;
    }
    cout << best[0] << " " << best[1] << endl;
}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}