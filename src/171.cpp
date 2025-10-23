# include <iostream>

using namespace std;

int main(){
    long long a,b;
    char ch;
    cin >> a >> b >> ch;
    if (ch == '+') cout << a + b << endl;
    else if (ch == '-') cout << a - b << endl;
    else if (ch == '*') cout << a * b << endl;
    else if (ch == '/' && b != 0) cout << a / b << endl;
    else if (ch == '%' && b != 0) cout << a % b << endl;
    else cout << "NO" << endl;


}