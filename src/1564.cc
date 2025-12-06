#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> dorms(n);
    for (int i = 0; i < n; ++i)
        cin >> dorms[i];

    unordered_map<string, vector<pair<string, int>>> dormMap;
    dormMap.reserve(n);
    for (auto &d : dorms)
        dormMap[d] = {};

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        string name, dorm;
        int power;
        cin >> name >> power >> dorm;
        dormMap[dorm].push_back({name, power});
    }

    int k;
    cin >> k;
    for (int t = 0; t < k; ++t)
    {
        string challenge;
        cin >> challenge;
        int pos = challenge.find("->");
        string A = challenge.substr(0, pos);
        string B = challenge.substr(pos + 2);

        long long sumA = 0, sumB = 0;
        for (auto &w : dormMap[A])
            sumA += w.second;
        for (auto &w : dormMap[B])
            sumB += w.second;

        if (sumA > sumB)
        {
            swap(dormMap[A], dormMap[B]);
        }
    }

    for (auto &d : dorms)
    {
        cout << d;
        auto &vec = dormMap[d];
        if (!vec.empty())
        {
            sort(vec.begin(), vec.end(), [](const auto &a, const auto &b)
                 { return a.first < b.first; });
            for (auto &w : vec)
                cout << " " << w.first;
        }
        cout << "\n";
    }
    return 0;
}