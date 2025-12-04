#include <bits/stdc++.h>
using namespace std;

int main(){
    int score[2] = {0, 0};
    int x;
    int status = true;
    while(cin >> x){
        score[x] ++;
        if(status && score[x] >= 21 && score[x] - score[1 - x] > 1){
            cout << x << endl;
            status = false;
        }
    }
    return 0;
}