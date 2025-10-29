#include <iostream>

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    int a = 0, b = 0, c = 0, d = 0;
    for(int i = 1; i <= n; i++){
        if(i % m == 0){
            if(i%4 == 1) a++;
            else if(i%4 == 2) b++;
            else if(i%4 == 3) c++;
            else d++;
        }
    }
    cout << a << " " << b << " " << c << " " << d;
}
int main(){solve(); return 0;}