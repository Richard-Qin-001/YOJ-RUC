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

vector<vector<int>> matrix_multiply(const vector<vector<int>>& m_1, const vector<vector<int>>& m_2){
    size_t n = m_1.size();
    size_t m = m_2.size();
    size_t p = m_2[0].size();
    vector<vector<int>> matrix(n, vector<int>(p));
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < p; j++){
            int combination = 0;
            for (size_t k = 0; k < m; k++){
                combination += m_1[i][k] * m_2[k][j];
            }
            matrix[i][j] = combination;
        }
    }
    return matrix;
}

vector<vector<int>> matrix_transpose(const vector<vector<int>>& matrix){
    size_t n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> transposed_matrix(m, vector<int>(n));
    for (size_t i = 0; i < n; i++){ 
        for (size_t j = 0; j < m; j++){ 
            transposed_matrix[j][i] = matrix[i][j];
        }
    }
    return transposed_matrix;
}

void print_matrix(const vector<vector<int>>& matrix){
    size_t n = matrix.size();
    size_t m = matrix[0].size();
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < m; j++){
            cout << matrix[i][j];
            if (j < m - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}
void solve(){
    int n, d;
    cin >> n >> d;
    vector<vector<int>> Q = input_matrix(n, d), K = input_matrix(n, d), V = input_matrix(n, d);
    vector<vector<int>> KT = matrix_transpose(K);
    vector<int> W(n);
    for(auto&c:W) cin >> c;
    vector<vector<int>> result_tmp = matrix_multiply(KT, V);
    vector<vector<int>> result = matrix_multiply(Q, result_tmp);
    for (int i = 0; i < n; i++) for(auto&a:result[i]) a = W[i] * a;
    print_matrix(result);
}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL);solve(); return 0;}