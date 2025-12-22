#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int n, m;
vector<vector<int>> a;
vector<vector<ll>> memo;

ll dfs(int i, int j){
    if (i < 1 || i > n || j < 1 || j > m)return 0;
    if (memo[i][j] != -1)return memo[i][j];
    ll res = max({dfs(i - 1, j), dfs(i, j + 1),(ll)a[i][j] + dfs(i - 1, j + 1)});
    return memo[i][j] = res;
}

void solve()
{
    cin >> n >> m;
    a.assign(n + 1, vector<int>(m + 1));
    memo.assign(n + 1, vector<ll>(m + 1, -1));

    for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)cin >> a[i][j];
    cout << dfs(n, 1) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}