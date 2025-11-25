#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N;
    cin >> N;
    string target;
    if(N < 10) target = to_string(N);
    else target = ('A' + N - 10);
    int space_num = 0;
    for(int i = 0; i < N; i++){
        for(int i = 0; i < space_num / 2; i++) cout << " ";
        for(int i = 0; i < 2 * N - 1 - space_num; i++) cout << target;
        cout << endl;
        space_num += 2;
    }
}
int main(){ios_base::sync_with_stdio(false);solve(); return 0;}