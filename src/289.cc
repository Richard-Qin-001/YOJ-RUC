#include <iostream>

using namespace std;
using ll = long long;

ll calculate(int a, int b, int c, int d, int e, int x){
    ll result = a * x *x *x *x + b * x * x* x + c * x * x + d * x + e;
    return result;
}

void solve(){
    int n, k;
    cin >> n >> k;
    int count1 = 0, count2 = 0;
    int score1 = 0, score2 = 0;
    for(int i = 0; i < n; i++){
        int a, b, c, d, e, x;
        ll ans1, ans2;
        cin >> a >> b >> c >> d >> e >> x >>ans1 >> ans2;
        ll result = calculate(a, b, c, d, e, x);
        if (result == ans1){
            count1++;
            if (count1 >= k){
                score1 += 1 + (count1 - k);
            }
            else score1 ++;
        }
        else if (result != ans1){
            count1 = 0;
        }
        if (result == ans2){
            count2++;
            if (count2 >= k){
                score2 += 1 + (count2 - k);
            }
            else score2 ++;
        }
        else if (result != ans2){
            count2 = 0;
        }

    }
    cout << score1 << " " << score2;
}
int main(){solve(); return 0;}