#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto&n:a)cin >> n;
    auto target_it = a.begin() + (k - 1);
    nth_element(a.begin(), target_it, a.end());
    cout << *target_it << endl;
    return 0;
}