#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main(){
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<ull> a(n);
    for(auto&i:a)cin >> i;
    ranges::sort(a, [](const ull&a, const ull&b){return a > b;});
    for(int i = 0; i < x; ++i)cout << a[i] << (i != x-1 ? " " : "\n");
    for (int i = x; i < y; ++i)cout << a[i] << (i != y - 1 ? " " : "\n");
    sort(a.begin()+y, a.begin() + z);
    for (int i = y; i < z; ++i)cout << a[i] << (i != z - 1 ? " " : "\n");
    return 0;
}