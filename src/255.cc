# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

void solve(int n, int m){
    int matrix[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    for (int j = 0; j < m; j++){
        for (int i = 0; i < n; i++){
            if (i != 0) cout << " ";
            cout << matrix[i][j];
        }
        cout << endl;
    }

}
int main(){
    int n, m;
    cin >> n >> m;
    solve(n, m);
    return 0;
}