# include <iostream>
 int main(){
    using namespace std;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << i*j << ' ';
        }
        cout << endl;
    }
    return 0;
 }