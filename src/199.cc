#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

bool compare(const vector<ll>&row1, const vector<ll>&row2){
    return row1[0] < row2[0];
}

void solve(){
    int n;
    cin >> n;
    vector<vector<ll>> log;
    for(int i = 0; i < n; i++){
        vector<ll> tmp(2);
        cin >> tmp[0] >> tmp [1];
        log.push_back(tmp);
    }
    sort(log.begin(), log.end(), compare);
    vector<vector<ll>> new_log;
    new_log.push_back(log[0]);
    int new_size = 0;
    for(int i = 1; i < n; i++){
        if (log[i][0] > new_log[new_size][1]){
            new_size++;
            new_log.push_back(log[i]);
        }
        else if (log[i][1] > new_log[new_size][1])  new_log[new_size][1] = log[i][1];
    }
    log = new_log;
    n = new_size + 1;
    ll max_online = 0;
    ll max_offline = 0;
    for(int i = 0; i < n - 1; i++){
        ll current_online = log[i][1] - log[i][0];
        ll current_offline = log[i+1][0] - log[i][1];
        max_online = max(max_online, current_online);
        max_offline = max(max_offline, current_offline);
    }
    max_online = max(max_online, log[n-1][1] - log[n-1][0]);
    cout << max_online << " " << max_offline << endl;
}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}