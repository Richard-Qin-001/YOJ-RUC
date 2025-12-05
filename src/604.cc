#include <bits/stdc++.h>
using namespace std;

constexpr inline auto josephus(int n, int m)
{
    int res = 0;
    for (int i = 2; i <= n; i++)
    {
        res = (res + m) % i;
    }
    return res + 1;
}

int main(){
    int n, m;
    cin >> n >> m;
    cout << josephus(n, m) << "\n";
    return 0;
}
