# include <iostream>
# include <cmath>
# include <string>


using namespace std;

void solve(int n){
    if (n == 0){
        return;
    }
    for (int i = 14; i >= 0; i--){
        if (n >= pow(2, i)){
            if (i == 1){
                cout << "2";
            }
            else if (i == 0){
                cout << "2(0)";
            }
            else{
                cout << "2(";
                solve(i);
                cout << ')';
            }
            n -= pow(2, i);
            if (n > 0){
                cout << '+';
            }

        }
    } 
}
int main(){
    int n;
    cin >> n;
    solve(n);
    cout << endl;
    return 0;
}