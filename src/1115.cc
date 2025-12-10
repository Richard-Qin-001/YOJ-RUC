#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll A, B, C;
    cin >> A >> B >> C;
    unordered_map<ll, int> H;
    ll ai = 1,ai_1;
    constexpr int max_limit = 2 * 1e6;
    H.reserve(max_limit);
    H[ai] = 0;
    for (int i = 1; i <= max_limit; ++i)
    {
        ai_1 = (A * ai + ai % B) % C;
        if (H.count(ai_1))
        {
            cout << i << endl;
            return 0;
        }
        H[ai_1] = i;
        ai = ai_1;
    }
    cout << -1 << endl;
    return 0;
}