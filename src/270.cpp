#include <iostream>

using namespace std;


int main(){
    int a, b;
    char ch;
    cin >> a >> ch >> b;
    for (int i = a; i >1; i--){
        if (a % i == 0){
            if (b % i == 0){
                a = a/i;
                b = b/i;
            }
        }
    }

    cout << a << ch << b;
    return 0;
}