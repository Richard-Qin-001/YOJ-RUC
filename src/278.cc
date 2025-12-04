#include <bits/stdc++.h>

using namespace std;

int process(int n){
    if(n == 1)return 1;
    if(n == 2)return 2;
    return process(n - 1) + process(n - 2);
}

int main(){
    int n;
    cin >> n;
    int total = process(n);
    cout << total << endl;
    return 0;
}