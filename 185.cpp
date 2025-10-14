# include <iostream>
# include <cmath>
# include <iomanip>
using namespace std;

double process(long double a, long double n){
    n = 0.5 * (n + a / n);
    return n;
}

int main(){
    int count = 0;
    long double a;
    cin >> a;
    long double d = 1.0;
    long double n = a/2;
    long double n_t;
    while( abs(d) >= pow(10, -5)){
        n_t = process(a, n);
        d = n_t - n;
        n = n_t;
        count++;
    }
    cout << fixed << setprecision(6);
    cout << n << endl;
    cout << count << endl;
    return 0;

}