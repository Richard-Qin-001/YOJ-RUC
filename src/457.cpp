# include <iostream>
using namespace std;

void cout_space(int n){
    for (int l = 1; l <= n ; l++){
        cout << " ";
    }
}

void cout_letter(int n){
    int ch = 65;
    if (n == 1) cout << "A";
    else {
    for (int k = 0; k < n; k++){
        cout << char(ch + k);
    }
    ch = ch + n - 1;
    for (int o = 1; o <= n-1; o++){
        cout << char(ch - o);
    }
    }
}

void process(int n){
    for (int i = 1; i <= n; i++){
        cout_space(n-i);
        cout_letter(i);
        cout << endl;

    }
}

int main(){
    int n;
    cin >>n;
    process(n);
    return 0;
}