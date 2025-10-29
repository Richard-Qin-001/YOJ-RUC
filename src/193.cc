#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

void solve(){
    ll n, m;
    cin >> n >> m;
    map<ll, ll> votes;
    for(ll i = 0; i < m; i++){
        int p;
        cin >> p;
        votes[p]++;
    }
    ll person = -1;
    ll max_v = 0;
    for(const auto&p : votes){
        if(p.second > m / 2 && p.second > max_v){
            person = p.first;
            max_v = p.second;
        }
    }
    cout << person << endl;
}
int main(){ios::sync_with_stdio(false);cin.tie(NULL);solve();return 0;}