#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> matrix;
vector<vector<int>> visited;
int start_x, start_y, card_x, card_y, target_x, target_y;
int total_time = (int)1e9, current_time = 0;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

void DFS(int x, int y, int tx, int ty){
    if(x == tx && y == ty){
        total_time = min(total_time, current_time);
        return;
    }
    if(current_time >= total_time)return;
    if(visited[x][y] == 2)return;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < n && nx >=0 && ny < n && ny >= 0 && matrix[nx][ny] != 1){
            current_time ++;
            visited[nx][ny]++;
            DFS(nx, ny, tx, ty);
            current_time--;
            visited[nx][ny]--;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    matrix.assign(n, vector<int> (n, 0));
    visited.assign(n, vector<int> (n, 0));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int t;
            cin >> t;
            matrix[i][j] = t;
            if(t == 2){
                start_x = i, start_y = j;
            }
            if(t == 3){
                card_x = i, card_y = j;
            }
            if(t == 4){
                target_x = i, target_y = j;
            }
        }
    }
    DFS(start_x, start_y, card_x, card_y);
    int time1 = total_time;
    total_time = (int)1e9, current_time = 0;
    DFS(card_x, card_y, target_x, target_y);
    int time2 = total_time;
    cout << time1 + time2 << endl;
    return 0;
}