#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

string num_str;
int N, K;

ll get_value(int start, int end){
    ll value = 0;
    for(int i = start; i <= end; i++)value = value * 10 + (num_str[i] - '0');
    return value;
}

void solve(){
    cin >> num_str >> K;
    N = num_str.length();
    vector<vector<ll>> dp(N + 1, vector<ll>(K+1,0));
    for(int i = 1; i <= N; i++) dp[i][0] = get_value(0, i-1);
    for(int i = 2; i <= N; i++)for(int j = 1; j <= K; j++)for(int x = j; x < i; x++){
        ll last_factor = get_value(x, i - 1);
        dp[i][j] = max(dp[i][j], dp[x][j - 1] * last_factor);
    }
    cout << dp[N][K] << endl;
}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();return 0;}