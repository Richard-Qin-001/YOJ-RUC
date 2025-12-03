#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visited;


const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

bool inBounds(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    int black = 0, white = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        if ((x + y) % 2 == 0) black++;
        else white++;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (inBounds(nx, ny) && !visited[nx][ny] && grid[nx][ny] == 0) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return max(black, white);
}

int main() {
    cin >> n >> m;
    grid.assign(n, vector<int>(m));
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];

    int total = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (!visited[i][j] && grid[i][j] == 0)
                total += bfs(i, j);

    cout << total << endl;
    return 0;
}