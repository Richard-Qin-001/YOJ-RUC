#include <iostream>
using namespace std;

bool check(int x){
    while (x > 0){
        int d = x % 10;
        if (d == 4)
            return false;
        if (d == 2 && (x / 10 % 10 == 6))
            return false;
        x /= 10;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)){
        int total = 0;
        for (int i = n; i <= m; ++i){
            if (check(i))total++;
        }
        cout << total << "\n";
    }
    return 0;
}