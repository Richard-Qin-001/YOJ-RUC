#include <bits/stdc++.h>
using namespace std;
using Matrix = vector<vector<int>>;

int n;

Matrix multiply(Matrix &A, Matrix &B)
{
    int M = A.size();
    int K = A[0].size();
    int N = B[0].size();
    Matrix C(M, vector<int>(N, 0));
    for (int i = 0; i < M; ++i)
    {
        for (int k = 0; k < K; ++k)
        {
            int temp = A[i][k];
            for (int j = 0; j < N; ++j)
            {
                C[i][j] += temp * B[k][j];
            }
        }
    }
    return C;
}

bool is_reflexive(const Matrix& matrix ) {
    for (int i = 0; i < n; ++i) {
        if(matrix[i][i] != 1) {
            return false;
        }
    }
    return true;
}

bool is_irreflexive(const Matrix& matrix) {
    for (int i = 0; i < n; ++i) {
        if (matrix[i][i] != 0) {
            return false;
        }
    }
    return true;
}

bool is_symmetric(const Matrix& matrix) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

bool is_antisymmetric(const Matrix& matrix) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (matrix[i][j] == 1 && matrix[j][i] == 1) {
                return false;
            }
        }
    }
    return true;
}

bool is_transitive(Matrix& matrix) {
    Matrix res = multiply(matrix, matrix);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (res[i][j] == 1 && matrix[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n;
    
    Matrix matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << (is_reflexive(matrix) ? 1 : 0) << " " << (is_irreflexive(matrix) ? 1 : 0) << " " << (is_symmetric(matrix) ? 1 : 0) << " " << (is_antisymmetric(matrix) ? 1 : 0) << " " << (is_transitive(matrix) ? 1 : 0) << endl;
    return 0;
}