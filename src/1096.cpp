#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp;
int main(){   
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a;
    cin >> a;
    int n;
    cin >> n;
    int maxx = -1;
    int len = a.size();
    for (int i = 0; i < len - n + 1; i++){
        // string b;
        //  b.assign(a, i, n);
        string b = a.substr(i, n);
        maxx = max(++mp[b], maxx);
    }
    cout << maxx;
}