# include <iostream>
using namespace std;

int main(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    for (int i = 0; i <= n; i++){
        if (i * a + (n - i) * b == m){
            cout << i << " " << n-i << endl;
            break;
        }
    }
    return 0;
}