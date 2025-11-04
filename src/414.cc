#include <iostream>
#include <vector>
#include <string>

using namespace std;

void process(int n){
    int nc = n;
    int a, b , c;
    a = nc % 10;
    nc /= 10;
    b = nc%10;
    nc/=10;
    c = nc;
    if(n == a*a*a + b*b*b + c*c*c) cout << n << " ";
    
}

void solve(){
    int m, n;
    cin >> m >> n;
    for (int i = m; i <= n; i++){
        process(i);
    }

}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}