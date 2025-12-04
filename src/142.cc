#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
    int m, n, k;
    cin >> m >> n >> k;
    vector<int> sort_columns(k);
    for (int i = 0; i < k; i++) cin >> sort_columns[i];
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    for(int i = 0; i < m; ++i)for(int j = 0; j < n; ++ j)cin >> matrix[i][j];
    sort(matrix.begin(), matrix.end(),[&sort_columns](const vector<int>& row1, const vector<int>& row2){
        for(auto&col1:sort_columns){
            int col0 = col1-1;
            if (row1[col0] != row2[col0])return row1[col0] < row2[col0];  
        }
        return row1[0] < row2[0];
        });
    for (const auto& row : matrix) {
        int len = row.size();
        for (int i = 0; i < len; ++i) cout << row[i] << ((i != len - 1) ? " " : "");
        cout << endl;
    }
}
int main(){ios::sync_with_stdio(false);cin.tie(NULL);solve(); return 0;}