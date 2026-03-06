#include <iostream>
using namespace std;

int main()
{
    int n;
    if (!(cin >> n))
        return 0;

    for (char who = 'A'; who <= 'D'; who++)
    {
        int count = 0;

        if (who != 'A')
            count++;

        if (who == 'C')
            count++;

        if (who == 'D')
            count++;

        if (who != 'D')
            count++;

        if (count == n)
        {
            cout << who << endl;
        }
    }

    return 0;
}