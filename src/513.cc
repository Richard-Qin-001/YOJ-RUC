#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
int m, n;
vector<vector<ll>> dp;

ll getnum(int i, int j, string str){
    ll result = 0;
    for(int k = i; k <= j; k++) result = result * 10 + str[k] - '0';;;
    return result;
}

void solve(){
    cin >> m  >> s;
    n = s.length();
    dp.assign(n, vector<ll>(m+1, 0));
    for(int i = n-1; i >=0; i--) dp[i][0] = getnum(i, n-1, s);
    for(int i = 1; i <= m; i++)for(int j = n-1; j >= 0; j--){
        dp[j][i] = -1;
        int max_k = n - i - 1;
        for(int k = j; k <= max_k; k++){
            ll num1 = getnum(j, k, s), num2 = dp[k+1][i-1];
            if(num1 + num2 > dp[j][i]) dp[j][i] = num1+num2;
        } 
    }
    cout << dp[0][m] << endl;
}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}