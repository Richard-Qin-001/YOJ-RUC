#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    map<int, int> counts; 
    for (int i = 0; i < n; ++i) {
        int element;
        if (!(cin >> element)) return;
        counts[element]++;
    }

    bool found_duplicate = false;
    for (const auto& pair : counts) {
        int element_value = pair.first;
        int element_count = pair.second;
        if (element_count > 1) {
            found_duplicate = true;
            cout << element_value << ":" << element_count << endl;
        }
    }
    if (!found_duplicate) {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}