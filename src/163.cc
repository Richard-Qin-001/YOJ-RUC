#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
int total_islands = 0, current_area = 0, max_area = 0;
vector<vector<bool>> visited;
int n, m;

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1}, dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

void visit_island(int x, int y){
    visited[x][y] = true;
    current_area++;
    int nx = 0, ny = 0;
    for(int i = 0; i < 8; ++i){
        nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '.' && !visited[nx][ny]){
            visit_island(nx, ny);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    grid.assign(n, vector<char>(m, '.'));
    visited.assign(n, vector<bool>(m, false));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!visited[i][j]){
                if(grid[i][j] == 'I'){
                    current_area = 0;
                    visit_island(i, j);
                    total_islands++;
                    max_area = max(max_area , current_area);
                }
            }
            visited[i][j] = true;
        }
    }
    cout << total_islands << " " << max_area << endl;
}