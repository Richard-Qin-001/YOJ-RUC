#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> tree(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)for(int j = 0; j <=i; j++)cin >> tree[i][j];
    dp[n-1] = tree[n-1];
    for(int i = n - 2; i >= 0; i--)for(int j = 0; j <= i; j++)dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + tree[i][j];
    cout << dp[0][0] << endl;
}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}