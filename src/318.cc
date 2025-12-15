#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int opt;
    cin >> opt;
    vector<vector<char>> matrix(n, vector<char>(n));
    for (auto &r : matrix)
        for (auto &c : r)
            cin >> c;

    map<vector<vector<char>>, int> cnt;
    vector<vector<char>> result(n, vector<char>(n));

    bool do1 = false, do2 = false, do3 = false, do4 = false;

    for (int i = 0; i < n; ++i)for (int j = 0; j < n; ++j)result[i][j] = matrix[i][n - 1 - j];
    cnt[result]++;
    do1 = true;
    
    for (int i = 0; i < n; ++i)for (int j = 0; j < n; ++j)result[i][j] = matrix[n - 1 - i][j];
    if (cnt.find(result) == cnt.end())
    {
        cnt[result]++;
        do2 = true;
    }

    if (opt == 1)
    {
        for (int i = 0; i < n; ++i)for (int j = 0; j < n; ++j)result[i][j] = matrix[n - 1 - j][n - 1 - i];
        if (cnt.find(result) == cnt.end())
        {
            cnt[result]++;
            do3 = true;
        }

        for (int i = 0; i < n; ++i)for (int j = 0; j < n; ++j)result[i][j] = matrix[j][i];
        if (cnt.find(result) == cnt.end())
        {
            cnt[result]++;
            do4 = true;
        }
    }
    cout << cnt.size() << "\n";
    bool first = true;

    if (do1)
    {
        if (!first)
            cout << "\n";
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                cout << matrix[i][n - 1 - j];
            cout << "\n";
        }
        first = false;
    }
    if (do2)
    {
        if (!first)
            cout << "\n";
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                cout << matrix[n - 1 - i][j];
            cout << "\n";
        }
        first = false;
    }
    if (opt == 1)
    {
        if (do3)
        {
            if (!first)
                cout << "\n";
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                    cout << matrix[n - 1 - j][n - 1 - i];
                cout << "\n";
            }
            first = false;
        }
        if (do4)
        {
            if (!first)
                cout << "\n";
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                    cout << matrix[j][i];
                cout << "\n";
            }
            first = false;
        }
    }

    return 0;
}