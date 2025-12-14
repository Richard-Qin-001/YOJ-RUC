#include <bits/stdc++.h>
using namespace std;

void solve(int n){
    bool first = true;
    for(int i = 17; i >= 0; --i){
        if((n >> i) & 1){
            if(!first) cout << "+";

            if(i == 0) cout << "2(0)";
            else if (i == 1) cout << "2";
            else if (i == 2) cout << "2(2)";
            else{
                cout << "2(";
                solve(i);
                cout << ")";
            }
            first = false;
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