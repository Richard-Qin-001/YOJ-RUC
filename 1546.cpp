# include <iostream>
# include <cmath>


int main(){
    using namespace std;
    long long n, a, b, c, d, ans = 0;
    cin >> n >> a >> b >> c >> d;
    ans = a * pow(n, 3) + b * pow(n, 2) + c * pow(n, 1) + d;
    cout << ans << endl;
    return 0;
}