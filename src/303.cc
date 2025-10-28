#include <iostream>
#include <iomanip>

using namespace std;

void solve(){
    double price;
    int num;
    cin >> price >> num;
    double sum;
    if(num == 1) sum = price * num;
    else if(num == 2) sum = price * num * 0.8;
    else if(num >= 3 && num <= 5) sum = price * num * 0.7;
    else {
        sum = price * 5 * 0.7 + (num - 5) * price * 1.1;
    }
    cout << fixed << setprecision(2);
    cout << sum;
}
int main(){solve(); return 0;}
