#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void solve(){
    double x;
    cin >> x;
    cout << fixed << setprecision(2);
    if(x < 0) cout << -x << endl;
    else if(x > 1) cout << x * x << endl;
    else cout << sqrt(x) << endl;
}
int main(){solve(); return 0;}