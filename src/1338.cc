#include <bits/stdc++.h>
using namespace std;
using Matrix = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    Matrix matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            bool first = true;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1)
                {
                    visited[j] = true;
                    if (!first){
                        cout << " ";
                    }
                    cout << j + 1;
                    first = false;
                }
            }
            cout << endl;
        }
    }
    return 0;
}