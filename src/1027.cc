#include <iostream>

using namespace std;

void solve(){
    int L, R;
    cin >> L >> R;
    int count = 0;
    for(int i = L; i <= R; i++)if(i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))count++;
    cout << count << endl;
}
int main(){solve(); return 0;}