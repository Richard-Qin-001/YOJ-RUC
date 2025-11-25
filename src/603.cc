#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<vector<int>>> results;
vector<bool> used;
vector<vector<int>> origin;
vector<vector<int>> result;
int t;

bool two_order_check(int n){
    int l1 = origin.size();
    for(int i = 0; i < l1; i++){
        int l2 = origin[i].size();
        for(int j = 0; j < l2; j++){
            if (n == origin[i][j]) return true;
        }
    }
    return false;
}

void complete_origin(){
    for(int i = 1; i <= N; i++)if(!two_order_check(i)){
        vector<int> temp = {i};
        origin.push_back(temp);
    }
}

void DFS(int pos){
    if(pos == t){
        results.push_back(result);
        return;
    }
    for(int i = 0; i < t; i++){
        if(!used[i]){
            result[pos] = origin[i];
            used[i] = true;
            DFS(pos+1);
            used[i] = false;
        }
    }
}

bool compare(const vector<vector<int>>&a, const vector<vector<int>>&b){
    for(int i = 0; i < t; i++)if(a[i][0] != b[i][0]) return a[i][0] < b[i][0];
    return false;
}

void solve(){
    cin >> N >> M;
    for(int i = 0; i < M; ++i){
        int mi;
        cin >> mi;
        vector<int> group(mi);
        for(int j = 0; j < mi; j++)cin >> group[j];
        origin.push_back(group);
    }
    complete_origin();
    t = origin.size();
    result.assign(t, vector<int>(1, 0));
    used.assign(t, false);
    DFS(0);
    sort(results.begin(), results.end(), compare);
    int total = results.size();
    for(int i = 0; i < total; i++){
        cout << i+1 << ".";
        for(int j = 0; j < t; j++){
            int len = results[i][j].size();
            for(int k = 0; k < len; k++) cout << " " << results[i][j][k];
        }
        cout << endl;
    }
}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}