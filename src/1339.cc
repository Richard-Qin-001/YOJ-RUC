#include <bits/stdc++.h>
using namespace std;
using Matrix = vector<vector<int>>;

void print_matrix(const Matrix &res)
{
    int n = res.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << (res[i][j] > 0 ? 1 : 0) << (j == n - 1 ? "" : " ");
        }
        cout << '\n';
    }
}

void get_reflexive(const Matrix &matrix)
{
    Matrix res = matrix;
    int n = matrix.size();
    for (int i = 0; i < n; ++i)
    {
        res[i][i] = 1;
    }
    print_matrix(res);
}

void get_symmetric(const Matrix &matrix)
{
    Matrix res = matrix;
    int n = matrix.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] == 1 || matrix[j][i] == 1)
            {
                res[i][j] = 1;
                res[j][i] = 1;
            }
        }
    }
    print_matrix(res);
}

void get_transitive(const Matrix &matrix)
{
    Matrix res = matrix;
    int n = matrix.size();

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            if (res[i][k] == 1)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (res[k][j] == 1)
                    {
                        res[i][j] = 1;
                    }
                }
            }
        }
    }
    print_matrix(res);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    Matrix matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "Reflexive Closure:\n";
    get_reflexive(matrix);
    cout << "Symmetric Closure:\n";
    get_symmetric(matrix);
    cout << "Transitive Closure:\n";
    get_transitive(matrix);

    return 0;
}