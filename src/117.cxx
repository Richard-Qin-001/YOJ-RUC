#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> tree;
int max_peers = 0;
vector<vector<int>> memo;
int dx[] = {-1, -1}, dy[] = {-1, 0};

int climb(int x, int y){
    if(x == 0)return tree[0][0];
    if (memo[x][y] != -1)return memo[x][y];
    int current = 0;
    int nx, ny;
    for(int i = 0; i < 2; ++i){
        nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && ny < x){
            current = max(climb(nx, ny), current);
        }
    }
    memo[x][y] = tree[x][y] + current;
    return memo[x][y];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    tree.assign(n, vector<int>(n));
    memo.assign(n, vector<int>(n, -1));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= i; ++j){
            cin >> tree[i][j];
        }
        for(int j = i + 1; j < n; ++j)tree[i][j] = - 1;
    }
    int max_peaches = 0;
    for(int i = 0; i < n; ++i){
        max_peaches = max(max_peaches, climb(n - 1, i));
    }
    cout << max_peaches << endl;
    return 0;

}