#include <bits/stdc++.h>
using namespace std;

bool check(int n, int m) {
    int coconuts = n;
    for (int i = 0; i < m; ++i) {
        if ((coconuts - 1) % m != 0) return false;
        coconuts = (coconuts - 1) * (m - 1) / m;
    }
    return coconuts % m == 0;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        int res = -1;
        for (int m = 10; m >= 2; --m) {
            if (check(n, m)) {
                res = m;
                break;
            }
        }
        if (res == -1) cout << "no solution" << endl;
        else cout << res << endl;
    }
    return 0;
}
