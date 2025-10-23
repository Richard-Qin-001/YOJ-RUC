# include <iostream>
using namespace std;

void solve(int n){
    int m = 0;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n - i; j++){
            for (int k = 0; k <= n - i - j; k++){
                if ((i + j + k == n) && (5 * i + 3 * j + (1.0/3.0)*k == n)){
                    cout << i << " " << j << " " << k << endl;
                    m++;

                }
            }
        }
    }
    cout << m;
}

int main(){
    int n;
    cin >> n;
    solve(n);
    return 0;
}