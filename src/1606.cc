#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
vector<vector<int>> matrix;
vector<string> canvas;
char Chr;

void fill_graph(int n, int r, int c)
{
    if (n == 1)
    {
        canvas[r][c] = Chr;
        return;
    }

    int cs = 1;
    for (int i = 0; i < n - 2; ++i)
        cs *= M;

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (matrix[i][j] == 1)
            {
                fill_graph(n - 1, r + i * cs, c + j * cs);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Chr;
    cin >> N >> M;
    matrix.assign(M, vector<int>(M, 0));
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> matrix[i][j];
        }
    }
    ll csize = 1;
    for (int i = 0; i < N - 1; ++i)
    {
        csize *= M;
    }
    canvas.assign(csize, string(csize, ' '));
    fill_graph(N, 0, 0);
    for (auto &line : canvas)
    {
        cout << line << "\n";
    }
    return 0;
}