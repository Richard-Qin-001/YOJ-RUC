# include <iostream>
# include <cmath>
# include <iomanip>
using namespace std;

int main(){
    double a, b, c, d, e;
    a = 1 + 1.0/5.0;
    for (int i = 0; i < 2; i++){
        a = 1 + 1.0/a;
    }
    b = pow(pow(3, 2)+pow(4,2),0.5);
    c = pow(0.5 * (1 - cos((M_PI/3))), 0.5);
    d = 2 * pow(sin(M_PI/4), 2) + sin(M_PI/4) * cos(M_PI/4) - pow(cos(M_PI/4), 2);
    e = (2 * pow(5, 0.5) * (pow(6 , 0.5) + pow(3, 0.5)))/(6.0 + 3.0);
    cout << fixed << setprecision(3) << a << endl;
    cout << fixed << setprecision(3) << b << endl;
    cout << fixed << setprecision(3) << c << endl;
    cout << fixed << setprecision(3) << d << endl;
    cout << fixed << setprecision(3) << e << endl;
    return 0;

}