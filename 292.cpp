# include <iostream>
# include <iomanip>

using namespace std;

double f(double x){
    if (abs(x) <= 1){
        return (abs(x -1) - 2);
    }
    else {
        return (1.0 / (1 + x * x));
    }
}

int main(){
    double x;
    cin >> x;
    cout << fixed << setprecision(2) << f(f(x)) << endl;return 0;
}