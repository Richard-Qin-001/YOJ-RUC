#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a, b, c, d, result = 0;
    cin >> a >> b >> c >> d;
    result += d / a;
    int empty_bottle = result, empty_coin = result;
    while (empty_bottle >= b || empty_coin >= c){
        int new_from_bottle = empty_bottle / b;
        int new_from_coin = empty_coin / c;
        int new_total = new_from_bottle + new_from_coin;
        result += new_total;
        empty_bottle %= b;
        empty_coin %= c;
        empty_bottle += new_total;
        empty_coin += new_total;
    }
    cout << result;
}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}