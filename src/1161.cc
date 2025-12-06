#include <bits/stdc++.h>
using namespace std;

int n;
int solutions = 0;
vector<bool> col, diag1, diag2;

void DFS(int r)
{
    if (r == n)
    {
        solutions++;
        return;
    }
    for (int c = 0; c < n; c++)
    {
        if (!col[c] && !diag1[r + c] && !diag2[r - c + n - 1])
        {
            col[c] = diag1[r + c] = diag2[r - c + n - 1] = true;
            DFS(r + 1);
            col[c] = diag1[r + c] = diag2[r - c + n - 1] = false;
        }
    }
}

int main()
{
    cin >> n;
    col.assign(n, false);
    diag1.assign(2 * n - 1, false);
    diag2.assign(2 * n - 1, false);
    DFS(0);
    cout << solutions << endl;
    return 0;
}