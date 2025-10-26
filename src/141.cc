#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> input_matrix(size_t n, size_t m){
    vector<vector<int>> matrix(n, vector<int>(m));
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < m; j++){
            if(!(cin >> matrix[i][j])) return {};
        }
    }
    return matrix;
}

int safe_get(const vector<vector<int>>& matrix, int r, int c) {
    int m = matrix.size();
    if (m == 0) return 0;
    int n = matrix[0].size();

    if (r >= 0 && r < m && c >= 0 && c < n) {
        return matrix[r][c];
    }
    return 0;
}

void calculate(const vector<vector<int>>& matrix, const int& i, const int& j, int& sum) {
    sum = 0;
    sum += safe_get(matrix, i - 1, j);
    sum += safe_get(matrix, i + 1, j); 
    sum += safe_get(matrix, i, j - 1); 
    sum += safe_get(matrix, i, j + 1); 
    sum += safe_get(matrix, i, j);
}

void solve(){
    size_t m, n;
    cin >> m >> n;
    vector<vector<int>> matrix = input_matrix(m, n);
    vector<vector<int>> result = {{0, 0, 0}};
    vector<int> tmp;
    for (int i =0; i < m; i++){
        for(int j = 0; j < n; j++){
            int sum;
            calculate(matrix, i, j, sum);
            if(sum > result[0][0]){
                result.clear();
                tmp = {sum, i, j};
                result.push_back(tmp);
            }
            else if (sum == result[0][0]){
                tmp = {sum, i, j};
                result.push_back(tmp);
            }
            else continue;

        }
    }
    size_t out = result.size();
    cout << result[0][0] << " " << out << endl;
    for (int i = 0; i < out; i++) cout << result[i][1] << " " << result[i][2]  << endl;

    
}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL);solve(); return 0;}