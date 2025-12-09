#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; ++i)
    {
        int x, y;
        cin >> x >> y;
        string mv;
        cin >> mv;
        int len = mv.length();
        for (int j = 0; j < len; ++j)
        {
            char m = mv[j];
            switch (m)
            {
            case 'f':
            {
                if (1 <= x && x <= n && 1 <= y + 1 && y + 1 <= n)
                    y++;
                break;
            }
            case 'b':
            {
                if (1 <= x && x <= n && 1 <= y - 1 && y - 1 <= n)
                    y--;
                break;
            }
            case 'l':
            {
                if (1 <= x - 1 && x - 1 <= n && 1 <= y && y <= n)
                    x--;
                break;
            }
            case 'r':
            {
                if (1 <= x + 1 && x + 1 <= n && 1 <= y && y <= n)
                    x++;
                break;
            }
            }
        }
        cout << x  << " " << y << endl;
    }
    return 0;
}