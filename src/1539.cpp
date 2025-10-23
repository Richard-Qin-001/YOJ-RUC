# include <iostream>
# include <cmath>

using namespace std;

int main(){
    int a, b, c, d;
    int num;
    cin >> a >> b >> c >> d;
    num = a * pow(2, 3) + b * pow(2, 2) + c * pow(2, 1) + d;
    cout << num << endl;
    return 0;
}