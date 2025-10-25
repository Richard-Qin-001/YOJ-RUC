#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

vector<vector<double>> matrix_multiply(const vector<vector<double>>& m_1, const vector<vector<double>>& m_2){
    size_t n = m_1.size();
    size_t m = m_2.size();
    size_t p = m_2[0].size();
    vector<vector<double>> matrix(n, vector<double>(p));
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < p; j++){
            double combination = 0;
            for (size_t k = 0; k < m; k++){
                combination += m_1[i][k] * m_2[k][j];
            }
            matrix[i][j] = combination;
        }
    }
    return matrix;
}

vector<vector<double>> input_matrix(size_t n, size_t m){
    vector<vector<double>> matrix(n, vector<double>(m));
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < m; j++){
            if(!(cin >> matrix[i][j])) return {};
        }
    }
    return matrix;
}

void sigma(vector<vector<double>>& matrix){
    for (auto&a:matrix) for (auto&b:a) b = 1/(1 + exp(-b));
}

void solve(){
    size_t m, d, n;
    cin >> m >> d >> n;
    vector<vector<double>> x = input_matrix(m, 1);
    vector<vector<double>> W = input_matrix(d, m);
    vector<vector<double>> V = input_matrix(n, d);
    vector<vector<double>> h = matrix_multiply(W, x);
    sigma(h);
    vector<vector<double>> o = matrix_multiply(V, h);
    sigma(o);
    cout << fixed << setprecision(2);
    for (auto&c : o) cout << c[0] << " ";
}
int main(){solve(); return 0;}