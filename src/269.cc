#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_M = 5;
const int MAX_N = 100000;
vector<vector<ll>> values(MAX_M + 1, vector<ll>(MAX_N + 1, -1));

ll ack(int m, int n){
    if(m == 0){
        values[0][n] = n + 1;
        return n + 1;
    }
    if(n == 0){
        values[m][0] = ack(m - 1, 1);
        return values[m][0];
    }
    if (values[m][n] != -1) return values[m][n];
    values[m][n] = ack(m - 1, ack(m, n - 1));
    return values[m][n];
}

int main(){
    int m, n;
    cin >> m >> n;
    ll result = ack(m, n);
    cout << result << endl;
    return 0;
}