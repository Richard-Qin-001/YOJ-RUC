#include <bits/stdc++.h>
using namespace std;

using Matrix = vector<vector<long long>>;
const int MOD = 1e9 + 7;


Matrix multiply(const Matrix &A, const Matrix &B, int m)
{
    Matrix C(m, vector<long long>(m, 0));
    for (int i = 0; i < m; ++i)
    {
        for (int k = 0; k < m; ++k)
        {
            if (A[i][k] == 0){
                continue;
            }
            for (int j = 0; j < m; ++j)
            {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix power(Matrix A, int n, int m)
{
    Matrix res(m, vector<long long>(m, 0));
    for (int i = 0; i < m; ++i)
        res[i][i] = 1;

    while (n > 0)
    {
        if (n & 1)
            res = multiply(res, A, m);
        A = multiply(A, A, m);
        n >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if (!(cin >> m >> n))
        return 0;

    Matrix matrix(m, vector<long long>(m));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    Matrix res = power(matrix, n, m);

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << (res[i][j] > 0 ? 1 : 0) << (j == m - 1 ? "" : " ");
        }
        cout << '\n';
    }

    return 0;
}