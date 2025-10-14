# include <iostream>
# include <iomanip>

int main(){
    using namespace std;
    double a, s = 0;
    int b;
    cin >> a >> b;
    if (b == 1 || b == 0){
        s = a * b;
    }
    else if (b >= 2 && b < 3){
        s = a * b * 0.8;
    }
    else if (b >= 3 && b < 5){
        s = a * b * 0.7;
    }
    else {
        s = a * 5 * 0.7 + a * (b - 5) * 1.1;
    }
    cout << fixed << setprecision(2) << s << endl;
    return 0;
}