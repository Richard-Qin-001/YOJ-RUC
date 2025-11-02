#include <iostream>

using namespace std;

void calculate(int y){
    for (int i = 0; i < y; i++){
        int x = i, x_c = i;
        int sum = x;
        while (x_c > 0)
        {
            sum += x_c%10;
            x_c /= 10;
        }
        if (sum == y){
            cout << i << endl;
            return;
        }
        
    }
    cout << 0 << endl;
}

void solve(void){
    int y = 0;
    while (true)
    {
        cin >> y;
        if (y == 0) return;
        calculate(y);
    }
}
int main(){solve(); return 0;}