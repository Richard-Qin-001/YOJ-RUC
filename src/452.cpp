# include <iostream>

int main(){
    using namespace std;
    char a, b, c;
    char separator1, separator2;
    cin >> a;
    cin.get(separator1);
    cin >> b;
    cin.get(separator2);
    cin >> c;
    cout << a << separator1 << b << separator2 << c << endl;
    return 0;
}