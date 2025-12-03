#include <bits/stdc++.h>
using namespace std;

int n, s, d;
vector<vector<int>> roads;
vector<bool> visited;
int global_min = 1e9, current_min = 0;
vector<vector<int>> solutions;
vector<int> solution;

void DFS(int k){
    if(k == d){
        if(current_min < global_min){
            solutions.clear();
            solutions.push_back(solution);
            global_min = current_min;
        }
        else if(current_min == global_min)solutions.push_back(solution);
        return;
    }
    if(current_min > global_min)return;
    for(int i = 0; i < n; i++){
        if(roads[k][i] != -1 && !visited[i]){
            visited[i] = true;
            current_min += roads[k][i];
            solution.push_back(i);
            DFS(i);
            visited[i] = false;
            current_min -= roads[k][i];
            solution.pop_back();
        }
    }
}

int main(){
    cin >> n >> s >> d;
    roads.assign(n, vector<int>(n));
    visited.assign(n, false);
    visited[s] = true;
    solution = {s};
    for(auto&r:roads)for(auto&c:r)cin >> c;
    DFS(s);
    if(solutions.size() == 0){
        cout << -1 <<  endl;
        return 0;
    }
    sort(solutions.begin(), solutions.end());
    int len = solutions[0].size();
    for(int i = 0; i < len; i++)cout << solutions[0][i] << ((i != len-1) ? "->" : ""); 

    return 0;
}