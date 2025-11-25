#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> maze;
vector<vector<int>> visited;
int dr[] = {1, 0, 0, -1};
int dc[] = {0, -1, 1, 0};

bool DFS(int r, int c){
    if(r == n - 1 && c == m - 1){
        return true;
    }
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr >= 0 && nr < n && nc >= 0 && nc < m)
        if( maze[nr][nc] == 1 && visited[nr][nc] == 0 ){
            visited[nr][nc] = 1;
            if(DFS(nr, nc)) return true;
            visited[nr][nc] = 0;
        }
    }
    return false;
};

void solve(){
    cin >> n >> m;
    maze.assign(n, vector<int>(m, 0));
    visited.assign(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++)for(int j = 0; j < m; j++) cin >> maze[i][j];
    if(DFS(0, 0)) cout << "YES" << endl;
    else cout << "NO" << endl;
};
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}