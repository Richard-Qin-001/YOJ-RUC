# include <iostream>
using namespace std;

int main(){
    long n;
    cin >> n;
    for (int i = 1; i <= 0.5 * n; i++){
        if (n % i == 0){
            cout << i << " ";
        }
    }
    cout << n << endl;
    return 0;
}