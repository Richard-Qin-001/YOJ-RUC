#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> matrix;
vector<vector<bool>> visited;

int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
int global_min = INT_MAX, total_min = 0;

void dfs(int x, int y){
    if(x == n - 1 && y == n - 1){
        global_min = min(global_min, total_min);
        return;
    }
    if (total_min >= global_min)
        return;
    int max_moves = matrix[x][y];
    int nx = 0, ny = 0;
    for(int i = max_moves; i >= 1; --i){
        for(int j = 0; j < 4; ++j){
            nx = x + dx[j] * i, ny = y + dy[j] * i;
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && (matrix[nx][ny] != 0 || (nx == n-1 && ny == n - 1))){
                visited[nx][ny] = true;
                total_min++;
                dfs(nx, ny);
                visited[nx][ny] = false;
                total_min--;
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    matrix.assign(n, vector<int>(n, 0)), visited.assign(n, vector<bool>(n, false));
    for(auto&r:matrix)for(auto&c:r)cin >> c;
    visited[0][0] = true;
    dfs(0, 0);
    cout << global_min << endl;
    return 0;
}