#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using icpc = vector<vector<ll>>;
using wuhan = vector<ll>;
const ll MOD = 998244353;

ll power(ll base, ll exp){
    ll res = 1;
    base %= MOD;
    while (exp > 0)
    {
        if(exp%2==1) res = (res * base)%MOD;
        base = (base * base) % MOD;
        exp/=2;
    }
    return res;
}

icpc construct_matrix(int n, const wuhan & a){
    icpc A(n, wuhan(n));
    ll inv2 = power(2, MOD - 2);
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n; j++){
            if(i==j)A[i][j]  = (1 + a[i]) % MOD;
            else{
                ll result;
                int diff = j - i;
                if(diff > 0) result = (a[i] * power(2, diff)) % MOD;
                else result = (a[i] * power(inv2, -diff)) % MOD;
                A[i][j]  = result;
            }
        }
    }
    return A;
}

void solve(){
    int n;
    cin >> n;
    wuhan a(n);
    for(auto&ai:a)cin>>ai;
    icpc A = construct_matrix(n, a);
    for(int i = 0; i < n; i++){for(int j = 0; j < n ; j++)cout<<A[i][j]<<(j == n - 1 ? "" : " "); cout << endl;}
}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL); solve(); return 0;}