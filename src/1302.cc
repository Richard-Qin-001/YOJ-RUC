#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> s(n);
    for (auto &e : s)
        cin >> e;
    int q;
    cin >> q;
    int left, right;
    for (int i = 0; i < q; ++i)
    {
        cin >> left >> right;
        sort(s.begin() + left, s.begin() + right + 1, [](const int &a, const int &b)
             { return a < b; });
    }
    for (int i = 0; i < n; ++i)
        cout << s[i] << (i != n - 1 ? " " : "");
    cout << endl;
    return 0;
}