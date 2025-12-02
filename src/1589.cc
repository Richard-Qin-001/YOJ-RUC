#include <bits/stdc++.h>
using namespace std;

    int m, n;
vector<vector<int>> matrix;
vector<vector<bool>> visited;
vector<vector<int>> dp;
vector<vector<int>> solutions;
vector<int> solution;
int total_max = 0, current_max = 1;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void DFS(int x, int y){
    if(visited[x][y]){
        return;
    }
    visited[x][y] = true;
    int nx = x + dx[matrix[x][y] - 1];
    int ny = y + dy[matrix[x][y] - 1];
    if(nx >= 0 && nx < n && ny >= 0 && ny < m){
        current_max++;
        DFS(nx, ny);
        
    }
    visited[x][y] =false;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >>  n;
    matrix.assign(n ,vector<int>(m, 0));
    visited.assign(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m;j++){
            DFS(i, j);
            if(current_max > total_max){
                solutions.clear();
                solution = {i, j};
                solutions.push_back(solution);
            }
            else if (current_max == total_max){
                solution = {i, j};
                solutions.push_back(solution);
            }
            current_max = 1;
        }
    }
    sort(solutions.begin(), solutions.end(), [](const vector<int>&a, const vector<int>&b){
        if(a[0] != b[0])return a[0] < b[0];
        return a[1] < b[1];
    });
    int len = solutions.size();
    for(int i = 0; i < len; i++){
        cout << solutions[i][0] << " " << solutions[i][1] << endl;
    }
    return 0;
}