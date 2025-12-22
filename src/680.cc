#include <bits/stdc++.h>
using namespace std;

int n, sum_val = 0, target_l = 0, m;
vector<int> sticks;
vector<bool> used;

bool dfs(int count, int current_l, int last_idx){
    if(count == m)return true;
    if(current_l == target_l) return dfs(count + 1, 0, 0);
    for(int i = last_idx; i < n; ++i){
        if(used[i] || current_l + sticks[i] > target_l)continue;
        used[i] = true;
        if (dfs(count, current_l + sticks[i], i + 1))return true;
        used[i] = false;
        if(current_l == 0)return false;
        if(current_l + sticks[i] == target_l)return false;
        while (i + 1 < n && sticks[i] == sticks[i + 1]) i++;   
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    sticks.assign(n, 0);
    int max_val = 0;
    for(int i = 0 ; i < n; ++i){
        cin >> sticks[i];
        sum_val += sticks[i];
        max_val = max(max_val, sticks[i]);
    }
    sort(sticks.begin(), sticks.end(), greater<int>());
    for(target_l = max_val; target_l <= sum_val; ++target_l){
        if(sum_val % target_l == 0){
            m = sum_val / target_l;
            used.assign(n, false);
            if(dfs(0, 0, 0)){
                cout << target_l << endl;
                return 0;
            }
        }
    }
    return 0;
}