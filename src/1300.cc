#include <bits/stdc++.h>
using namespace std;

int main()
{
    double price;
    int num;
    cin >> price >> num;
    double total = 0;
    for (int i = 0; i < num; ++i)
    {
        if (i % 2 == 0)
            total += price;
        else
            total += price / 2.0;
    }
    cout << fixed << setprecision(2);
    cout << total << endl;
    return 0;
}