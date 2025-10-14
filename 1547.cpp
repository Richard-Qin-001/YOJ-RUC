# include <iostream>
# include <iomanip>

int main(){
    using namespace std;
    double a, b, c;
    char op;
    cin >> a >> op >> b >> op >> c;
    cout << fixed << setprecision(2) << a + b + c << endl;
    return 0;
}