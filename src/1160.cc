#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> grid;
vector<vector<ll>> memo;
int n, m;
int dx[] = {0, 1}, dy[] = {1, 0};

ll dfs(int x, int y, int tx, int ty){
    if (x == tx && y == ty)return 1;
    if (memo[x][y] != -1)return memo[x][y];
    ll res = 0;
    int nx, ny;
    for (int i = 0; i < 2; ++i){
        nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx <= tx && ny >= 0 && ny <= ty && grid[nx][ny] == 0)res += dfs(nx, ny, tx, ty);
    }
    return memo[x][y] = res;
}

int dbx[] = {-1, -2, -2, -1, 1, 2, 2, 1}, dby[] = {-2, -1, 1, 2, -2, -1, 1, 2};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    grid.assign(n + 1, vector<int>(m + 1, 0));
    memo.assign(n + 1, vector<ll>(m + 1, -1));
    int bx, by;
    cin >> bx >> by;
    if (bx >= 0 && bx <= n && by >= 0 && by <= m)
        grid[bx][by] = 1;
    int nbx, nby;
    for (int i = 0; i < 8; ++i)
    {
        nbx = bx + dbx[i], nby = by + dby[i];
        if (nbx >= 0 && nbx <= n && nby >= 0 && nby <= m)
            grid[nbx][nby] = 1;
    }
    if (grid[0][0] == 1){
        cout << 0 << endl;
        return 0;
    }
    ll path_eat = 0;
    ll path_no_eat = dfs(0, 0, n, m);
    if (bx >= 0 && bx <= n && by >= 0 && by <= m){
        ll ways_to_knight = 0;
        memo.assign(n + 1, vector<ll>(m + 1, -1));
        grid[bx][by] = 0;
        ways_to_knight = dfs(0, 0, bx, by);
        ll ways_from_knight = 0;
        grid.assign(n + 1, vector<int>(m + 1, 0));
        memo.assign(n + 1, vector<ll>(m + 1, -1));
        ways_from_knight = dfs(bx, by, n, m);
        path_eat = ways_to_knight * ways_from_knight;
    }
    cout << path_eat + path_no_eat << endl;
    return 0;
}