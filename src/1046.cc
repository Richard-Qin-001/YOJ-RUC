#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<vector<vector<int>>> matrix(N, vector<vector<int>>(N, vector<int>(2)));
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < 2 * N; ++j){
            cin >> matrix[i][j / 2][j % 2];
        }
    }
    int x = 0, y = 0;
    int nx, ny;
    visited[0][0] = true;
    vector<vector<int>> solutions;
    while (true)
    {
        if(x == N - 1 && y == N - 1){
            solutions.push_back({x, y});
            int len = solutions.size();
            for(int i = 0; i < len; i++){
                cout << solutions[i][0] << " " << solutions[i][1] << endl;
            }
            return 0;
        }
        nx = matrix[x][y][0], ny = matrix[x][y][1];
        if((nx == -1 || ny == -1) || visited[nx][ny]){
            cout << "no" << endl;
            return 0;
        }
        visited[nx][ny] = true;
        solutions.push_back({x, y});
        x = nx, y = ny;
    }
    return 0;
}