#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a, b;
int check(int start_val){
    a[0] = start_val;
    a[1] = b[0] - start_val;
    if(a[1] < 0 || a[1] >1)return 0;
    for(int i = 1; i < n - 1; ++i){
        a[i + 1] = b[i] - a[i] - a[i - 1];
        if(a[i + 1] < 0 || a[i + 1] > 1)return 0;
    }
    if(a[n - 2] + a[n - 1] == b[n - 1])return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    a.assign(n, 0), b.assign(n, 0);
    for(int i = 0; i < n; ++i)cin >> b[i];
    cout << check(0) + check(1) << endl;
    return 0;
}