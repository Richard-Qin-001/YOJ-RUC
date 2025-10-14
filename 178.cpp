# include <iostream>

using namespace std;

void judge(int n){
    if (n <= 1) {cout << "NO "; return;}
    int state = 0;
    for (int i = 1; i * i <= n; i++){
        if (i !=1 && n % i == 0) {state = 1;break;};
    }
    if (state == 0) cout << "YES ";
    else cout << "NO ";
}

int main(){
    int n;
    cin >> n;
    int input;
    for (int m = 1; m <= n; m++){
        cin >> input;
        judge(input);
    }
    return 0;
}