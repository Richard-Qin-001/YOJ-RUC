# include <iostream>
# include <cmath>
# include <iomanip> 

int main(){
    using namespace std;
    int a, b, c;
    double s, p;
    cin >>a >> b >>c;
    p = (a + b + c) / 2.0;
    s = sqrt(p*(p - a)*(p - b)*(p - c));
    cout << fixed << setprecision(2) << s << endl;
    return 0;
    
}