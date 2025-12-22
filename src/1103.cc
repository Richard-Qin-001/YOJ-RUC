#include <bits/stdc++.h>
using namespace std;

int target[5][5] = {
    {1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1},
    {0, 0, 2, 1, 1},
    {0, 0, 0, 0, 1}, 
    {0, 0, 0, 0, 0}
};
vector<vector<int>> board(5, vector<int>(5));
int max_dep = 0;
bool success = false;
int dep = 0;

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1}, dy[8] = {-2, -1, 1, 2, -2, -1, 1, 2};

int get_cost(){
    int cost = 0;
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            if(board[i][j] != target[i][j])cost++;
        }
    }
    return cost;
}

void dfs(int x, int y){
    int cost = get_cost();
    if(cost == 0){
        success = true;
        return;
    }
    if(dep + cost > max_dep + 1)return;
    int nx, ny;
    for(int i = 0; i < 8; ++ i){
        nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5){
            swap(board[x][y], board[nx][ny]);
            dep++;
            dfs(nx, ny);
            if(success)return;
            dep--;
            swap(board[x][y], board[nx][ny]);
        }
    }
}

void solve(){
    char ch;
    int sx, sy;
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            cin >> ch;
            if(ch == '*'){
                sx = i, sy = j;
                ch = '2';
            }
            board[i][j] = ch - '0';
        }
    }
    dep = 0;
    success = false;
    for(max_dep = 0; max_dep <= 15; ++max_dep){
        dep = 0;
        dfs(sx, sy);
        if(success){
            cout << max_dep << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)solve();
    return 0;
}