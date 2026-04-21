#include <bits/stdc++.h>
using namespace std;

string s;
int n;
vector<string> all_partitions;
vector<string> curr_sets;

void dfs(int idx) {
    if (idx == n) {
        vector<string> sorted_subs = curr_sets;
        sort(sorted_subs.begin(), sorted_subs.end());
        string res = "";
        for (int i = 0; i < sorted_subs.size(); ++i) {
            res += sorted_subs[i];
            if (i != sorted_subs.size() - 1) {
                res += '0';
            }
        }
        all_partitions.push_back(res);
        return;
    }
    char c = s[idx];
    for (int i = 0; i < curr_sets.size(); ++i) {
        curr_sets[i].push_back(c);
        dfs(idx + 1);
        curr_sets[i].pop_back();
    }

    string new_sub = "";
    new_sub += c;
    curr_sets.push_back(new_sub);
    dfs(idx+1);
    curr_sets.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    n = s.length();

    dfs(0);

    sort(all_partitions.begin(), all_partitions.end());

    cout << all_partitions.size() << "\n";
    for (const string &res : all_partitions)
    {
        cout << res << "\n";
    }

    return 0;
}