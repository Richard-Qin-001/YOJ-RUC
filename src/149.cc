# include <iostream>
# include <vector>

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


void solve(){
    int n, p, m;
    cin >> n >> p >> m;
    vector<vector<int>> A = input_matrix(n, p), B = input_matrix(p, m), C = matrix_multiply(A, B);
    print_matrix(C);
}

int main(){solve(); return 0;}