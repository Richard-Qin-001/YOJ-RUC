#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<bool> is_lighted_up;
vector<vector<bool>> contractions;
vector<vector<int>> solutions;
vector<int> solution;
int max_size = 0, current_size = 0;

bool check(int idx){
    if(is_lighted_up[idx])return false;
    for(int i = 1; i <= n; i++)if(contractions[idx][i] && is_lighted_up[i])return false;
    return true;
}

void DFS(int k){
    if(k > n){
        current_size = solution.size();
        if(current_size > max_size){
            max_size = current_size;
            solutions.clear();
            solutions.push_back(solution);
        }
        else if(current_size == max_size){
            solutions.push_back(solution);
        }
        return;
    }
    if(solution.size() + n - k + 1 < max_size)return;
    if(check(k)){
        solution.push_back(k);
        is_lighted_up[k] = true;
        DFS(k+1);
        is_lighted_up[k] = false;
        solution.pop_back();
    }
    DFS(k + 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    is_lighted_up.assign(n + 1, false);
    contractions.assign(n + 1, vector<bool>(n + 1, false));
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        contractions[a][b] = contractions[b][a] = true;
    }
    DFS(1);
    sort(solutions.begin(), solutions.end());
    int total = solutions.size();
    for(int i = 0; i < total; ++i){
        for(int j = 0; j < max_size; ++j){
            cout << solutions[i][j];
            if(j != max_size - 1)cout << " ";
        }
        cout <<  endl;
    }
}