# include <iostream>
# include <vector>
using namespace std;

vector<vector<int>> input_matrix(int n, int m){
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(!(cin >> matrix[i][j])) return {};
        }
    }
    return matrix;
}

vector<vector<int>> matrix_multiply(vector<vector<int>> m_1, vector<vector<int>> m_2, int n, int m, int p){
    vector<vector<int>> matrix(n, vector<int>(p));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < p; j++){
            int combination = 0;
            for (int k = 0; k < m; k++){
                combination += m_1[i][k] * m_2[k][j];
            }
            matrix[i][j] = combination;
        }
    }
    return matrix;
}

void print_matrix(vector<vector<int>> matrix, int n, int p){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < p; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<int>> m_1 = input_matrix(n, m);
    vector<vector<int>> m_2= input_matrix(m, p);
    vector<vector<int>> matrix = matrix_multiply(m_1, m_2, n, m, p);
    print_matrix(matrix, n, p);
    return 0;

}