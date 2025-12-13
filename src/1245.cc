#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(ll x){
    if (x == 0)return false;
    int sum = 0;
    int count = 0;
    while (x > 0)
    {
        sum += x % 10;
        count++;
        x /= 10;
    }
    return sum > 4 * count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;

    ll a = 0, b = 1;
    int ans = 0;

    if (a < n && check(a))
        ans++;

    while (b < n)
    {
        if (check(b))
            ans++;

        ll next = a + b;
        a = b;
        b = next;

        if (a > n)
            break;
    }
    cout << ans << endl;
    return 0;
}