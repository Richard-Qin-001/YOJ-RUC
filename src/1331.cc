#include <bits/stdc++.h>
using namespace std;

string s;
string path;

void dfs(int idx) {
    for (int i = idx; i < s.length(); i++) {
        path.push_back(s[i]);
        cout << path << '\n';
        dfs(i + 1);
        path.pop_back();
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> s;

    sort(s.begin(), s.end());
    dfs(0);
    exit(0);
}