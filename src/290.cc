#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
    int n;
    cin >> n;
    map<int, int> dict;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        for(int j = 0; j < m; j++){
            int good;
            cin >> good;
            dict[good]++;
        }
    }
    vector<int> list;
    for(auto&p:dict)if(p.second == n) list.push_back(p.first);
    if (list.empty())cout << "NO" << endl;
    else for(auto&i:list) cout << i << " ";
    cout << endl;
}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();return 0;}