#include <iostream>
#include <vector>

using namespace std;

int N, M;
int max_treasure = -200 * 64;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int dr[] = {1, 0, 0};
int dc[] = {0, -1, 1};

void DFS(int r, int c, int current_sum){
    if (r == N-1 && c == M-1) {max_treasure = max(max_treasure, current_sum); return;}
    for (int i = 0; i < 3; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < N && nc >= 0 && nc < M) if(!(visited[nr][nc])){
            visited[nr][nc] = true;
            DFS(nr, nc, current_sum + grid[nr][nc]);
            visited[nr][nc] = false;
        }
    }
}
void solve(){
    cin >> N >> M;
    grid.assign(N, vector<int>(M));
    visited.assign(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> grid[i][j];
    visited[0][0] = true;
    DFS(0, 0, grid[0][0]);
    cout << max_treasure << endl;
}
int main(){solve(); return 0;}