#include <bits/stdc++.h>
using namespace std;

int main(){
    double x;
    cin >> x;
    double result;
    if(x < 0)result = -x;
    else if(x >= 0 && x <= 1)result = sqrt(x);
    else result = pow(x, 2);
    cout << fixed << setprecision(2) << result << endl;
    return 0;
}