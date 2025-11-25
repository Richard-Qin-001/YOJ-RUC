#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<vector<int>> height, visited;
int max_len = 0, current_len = 1;

int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};

bool check(int current_row, int current_col, int goto_row, int goto_col){
    if (goto_row < 0 || goto_row >= R || goto_col < 0 || goto_col >= C) return false;
    return (height[current_row][current_col] > height[goto_row][goto_col]) && (visited[goto_row][goto_col] == 0);
}

void DFS(int row, int col){
    visited[row][col] = 1;
    max_len = max(max_len, current_len);
    int goto_row, goto_col;
    for(int i = 0; i < 4; i++){
        goto_row = row + dr[i];
        goto_col = col + dc[i];
        if(check(row, col, goto_row, goto_col)){
            current_len++;
            DFS(goto_row, goto_col);
            current_len--;
        }
    }
    
    visited[row][col] = 0;
}

void solve(){
    cin >> R >> C;
    height.assign(R, vector<int>(C, 0));
    visited.assign(R, vector<int>(C, 0));
    for(auto&r:height)for(auto&c:r)cin >> c;
    for(int i = 0; i < R; i++)for(int j = 0; j < C; j++)DFS(i, j);
    cout << max_len << endl;
}

int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}