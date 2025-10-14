# include <iostream>
# include <iomanip>
# include <cmath>

int main(){
    using namespace std;
    double a, b;
    cin >> a >> b;
    cout << fixed << setprecision(2) << sqrt(a * b) << endl;
    return 0;
}