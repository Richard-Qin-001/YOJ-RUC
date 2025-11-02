#include <iostream>
#include <unordered_map>

using namespace std;
using ll = long long;

void solve(){
    ll n;
    cin >> n;
    ll sum = 0;
    unordered_map<int, int> dict;
    for(ll i = 0; i < n; i++){
        ll m = 0;
        cin >> m;
        for(ll j = 0; j < m; j++){
            int si;
            cin >> si;
            dict[si]++;
        }
    }
    for(auto&p:dict)if(p.second==1)sum += p.first;
    cout << sum;
}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve(); return 0;}