#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> matrix;
vector<int> match;
vector<bool> visited;

bool dfs(int u){
    for(int v = 0; v < n; ++v){
        if(matrix[u][v] == 1 && !visited[v]){
            visited[v] = true;
            if (match[v] == -1 || dfs(match[v])){
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    int cnt;
    while (T--)
    {
        cin >> n;
        matrix.assign(n, vector<int>(n));
        match.assign(n, -1);
        cnt = 0;
        for(auto&r:matrix)for(auto&c:r)cin >> c;
        for (int i = 0; i < n; ++i)
        {
            visited.assign(n, false);
            if (dfs(i))
                cnt++;
        }
        if(cnt == n) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}