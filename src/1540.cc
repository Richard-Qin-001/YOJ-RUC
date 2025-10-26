#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int x, k;
    cin >> x >> k;
    vector<int> transformed_num(4, 0);
    for (int i = 3; i >= 0; i--){
        int remainder = x % k;
        transformed_num[i] = remainder;
        x /= k;
    }
    for (auto&c:transformed_num) cout << c;
    cout << endl;
}
int main(){solve(); return 0;}