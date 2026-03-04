#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int L = 0;
    int R = n - 1;

    while (L < R && k > 0)
    {
        ll left_cnt = L + 1;
        ll right_cnt = n - R;

        if(left_cnt <= right_cnt){
            ll diff = a[L+1] - a[L];
            ll cost = left_cnt * diff;

            if (k >= cost){
                k -= cost;
                L++;
            }
            else{
                a[L] += k / left_cnt;
                k = 0;
                break;
            }
        }
        else{
            ll diff = a[R] - a[R-1];
            ll cost = right_cnt * diff;

            if (k >= cost){
                k -= cost;
                R--;
            }
            else{
                a[R] -= k / right_cnt;
                k = 0;
                break;
            }
        }
    }
    cout << a[R] - a[L] << "\n";
    return 0;
}