#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main(){
    ull x;
    vector<ull> a;
    while(cin >> x){
        if (x == 0)break;
        a.emplace_back(x);
    }
    int len = a.size();
    reverse(a.begin(), a.end());
    for(int i = 0; i < len; ++i)cout << a[i] << (i != len - 1 ? " " : "\n");
    return 0;
}