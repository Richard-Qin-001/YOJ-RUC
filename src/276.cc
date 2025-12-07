#include <bits/stdc++.h>
using namespace std;

static bool isLeap(int y)
{
    return (y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0));
}

static int days_in_year(int y)
{
    return isLeap(y) ? 366 : 365;
}

static int dowJan1(int y)
{
    long long D = 0;
    for (int yr = 1900; yr < y; ++yr)
        D += days_in_year(yr);
    return (1 + D) % 7;
}

static constexpr int mlensCommon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static void add_days_to_date(int y, int offset, int &m, int &d)
{
    int mlens[12];
    for (int i = 0; i < 12; ++i)
        mlens[i] = mlensCommon[i];
    if (isLeap(y))
        mlens[1] = 29;
    for (int i = 0; i < 12; ++i)
    {
        if (offset < mlens[i])
        {
            m = i + 1;
            d = offset + 1;
            return;
        }
        offset -= mlens[i];
    }
    m = 12;
    d = 31;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--)
    {
        int year, weekno;
        cin >> year >> weekno;

        if (year < 1980 || year > 2040 || weekno < 1 || weekno > 54)
        {
            cout << -1 << "\n";
            continue;
        }

        int d0 = dowJan1(year);
        int offset = -1;

        if (weekno == 1)
        {
            if (d0 <= 2)
            {
                offset = 2 - d0;
            }
            else
            {
                cout << -1 << "\n";
                continue;
            }
        }
        else
        {
            if (d0 == 0)
            {
                offset = 9 + 7 * (weekno - 2);
            }
            else
            {
                offset = (9 - d0) + 7 * (weekno - 2);
            }
        }

        if (offset < 0 || offset >= days_in_year(year))
        {
            cout << -1 << "\n";
            continue;
        }
        int m, d;
        add_days_to_date(year, offset, m, d);
        cout << setw(4) << setfill('0') << year
             << setw(2) << setfill('0') << m
             << setw(2) << setfill('0') << d << "\n";
    }
    return 0;
}