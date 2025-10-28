# include <iostream>
# include <iomanip>

int main(){
    using namespace std;
    int f;
    double c;
    cin >> f;
    c = (f - 32) * 5.0 / 9.0;
    cout << fixed << setprecision(2) << c << endl;
    return 0;

}