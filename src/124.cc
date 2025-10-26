#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int R, C;
vector<vector<int>> height, dp;

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

int DFS(int r, int c){
    if (dp[r][c] > 0) {
        return dp[r][c];
    }
    dp[r][c] = 1;
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
            if (height[nr][nc] < height[r][c]) {
                dp[r][c] = max(dp[r][c], 1 + DFS(nr, nc));
            }
        }
    }
    return dp[r][c];
}

void solve(){
    cin >> R >> C;
    height.resize(R, vector<int>(C));
    dp.resize(R, vector<int>(C, 0));
    for(int i = 0; i < R; i++)for(int j = 0; j < C; j++)cin >> height[i][j];
    int maxLength = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            maxLength = max(maxLength, DFS(i, j));
        }
    }
    cout << maxLength << endl;
}
int main(){solve(); return 0;}