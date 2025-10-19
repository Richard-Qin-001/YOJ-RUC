# include <iostream>
# include <vector>

using namespace std;

int forward_1(vector<vector<int>>& matrix, int n, int count){
    for (int i = 0; i < n; i++){
        count++;
        matrix[i][n-1] = count;
    }
    for (int i = n - 2; i >= 0; i--){
        count++;
        matrix[n-1][i] = count;
    }
    return count;
}

int forward_2(vector<vector<int>>& matrix, int n, int count){
    for (int i = 0; i < n; i++){
        count++;
        matrix[n-1][i] = count;
    }
    for (int i = n - 2; i >= 0; i--){
        count++;
        matrix[i][n-1] = count;
    }
    return count;
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

int main(void){
    int n;
    int count = 1;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int> (n));
    if (n == 1) matrix[n][n] = 1;
    else {
        matrix[0][0] = 1;
        for (int j = 2; j < n+1; j++){
            if (j % 2 == 0){
                count = forward_1(matrix, j, count);
            }
            else count = forward_2(matrix, j, count);

        }
    }
    print_matrix(matrix);
    return 0;
}