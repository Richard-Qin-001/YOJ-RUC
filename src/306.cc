#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_map<int, int> freq;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        freq[t]++;
    }
    vector<vector<int>> table;
    for(auto&n:freq)table.push_back({n.first, n.second});
    sort(table.begin(), table.end(), [](const vector<int>&a, const vector<int>&b){
        if(a[1] != b[1])return a[1] > b[1];
        return a[0] > b[0];
    });
    int m = table[0][1];
    int len = table.size();
    for(int i = 0; i < len; ++i){
        if(table[i][1] != m) goto end_loop;
    }
    cout << "NO" << endl;
    return 0;
end_loop:
cout << table[0][0] << " " << table[0][1] << endl;
return 0;
}