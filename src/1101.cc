#include <bits/stdc++.h>
using namespace std;

int n, sum_val = 0, target_val = 0, m;
vector<int> pieces;
vector<bool> used;

bool dfs(int count, int current_val, int last_idx){
    if(count == m)return true;
    if(current_val == target_val)return dfs(count + 1, 0, 0);
    for(int i = last_idx; i < n; ++i){
        if(used[i] || current_val + pieces[i] > target_val)continue;
        used[i] = true;
        if(dfs(count, current_val + pieces[i], i + 1))return true;
        used[i] = false;
        if(current_val == 0)return false;
        if(current_val + pieces[i] == target_val)return false;
        while(pieces[i] == pieces[i+1])i++;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    pieces.assign(n, 0);
    int max_val = 0;
    for(int i = 0; i < n; ++i){
        cin >> pieces[i];
        sum_val += pieces[i];
        max_val = max(max_val ,pieces[i]);
    }
    sort(pieces.begin(), pieces.end(), greater<int>());
    for(target_val = max_val; target_val <= sum_val; ++target_val){
        if(sum_val % target_val == 0){
            m  = sum_val / target_val;
            used.assign(n, false);
            if(dfs(0, 0, 0)){
                cout << target_val << endl;
                return 0;
            }
        }
    }
    return 0;
}