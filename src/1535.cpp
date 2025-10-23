# include <iostream>

int main(){
    using namespace std;
    long long a, b, c, d, e, sum;
    cin >> a >> b >> c >> d >> e;
    sum  = a + b + c - d - e;
    cout << a << "+" << b << "+" << c << "-" << d << "-" << e << "=" << sum << endl;
    return 0;
}