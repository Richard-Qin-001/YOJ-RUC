# include <iostream>
# include <iomanip>
using namespace std;
int main(){
    int n;
    cin >> n;
    double a = 4.0;
    if (n >= 90 && n <= 100) cout << fixed << setprecision(1) << a;
    else if (n >= 86 && n <= 89) cout << 3.7;
    else if (n >= 83 && n <= 85) cout << 3.3;
    else if (n >= 80 && n <= 82) cout << 3.0;
    else if (n >= 76 && n <= 79) cout << 2.7;
    else if (n >= 73 && n <= 75) cout << 2.3;
    else if (n >= 70 && n <= 72) cout << 2.0;
    else if (n >= 66 && n <= 69) cout << 1.7;
    else if (n >= 63 && n <= 65) cout << 1.3;
    else if (n >= 60 && n <= 62) cout << 1.0;
    else cout << 0;
    return 0;

}