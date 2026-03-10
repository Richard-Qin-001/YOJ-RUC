#include <bits/stdc++.h>
using namespace std;

int main(){
    bool all_equivalent = true;
    
    for (int i = 0; i < 32; ++i){
        bool A = (i >> 4) & 1;
        bool B = (i >> 3) & 1;
        bool C = (i >> 2) & 1;
        bool D = (i >> 1) & 1;
        bool E = (i >> 0) & 1;

        bool f1 = (A || B || C) && (!D || E);
        bool f2 = (A && D) || (B && E) || (C && D);

        if (f1 != f2) {
            all_equivalent = false;
            break;
        }
    }

    if (all_equivalent) {
        cout << "等价" << endl;
    }
    else {
        cout << "不等价" << endl;
    }
    return 0;
}