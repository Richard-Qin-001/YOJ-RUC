#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int A, B;
    cin >> A >> B;
    int val;
    int total_a = 0, total_b = 0;
    for (int i = 0; i < A; ++i)
    {
        cin >> val;
        total_a += val;
    }
    for (int i = 0; i < B; ++i)
    {
        cin >> val;
        total_b += val;
    }
    if (total_a > 21 && total_b > 21)
    {
        cout << "Draw with " << total_a << " and " << total_b << " points";
        return 0;
    }
    if (total_a > 21 && total_b <= 21)
    {
        cout << "B wins with " << total_b << " points";
        return 0;
    }
    if (total_b > 21 && total_a <= 21)
    {
        cout << "A wins with " << total_a << " points";
        return 0;
    }
    if (total_a > total_b)
    {
        cout << "A wins with " << total_a << " points";
        return 0;
    }
    if (total_a < total_b)
    {
        cout << "B wins with " << total_b << " points";
        return 0;
    }
    return 0;
}