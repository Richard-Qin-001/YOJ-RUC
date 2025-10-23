# include <iostream>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b;
    if (a > b){
        c = a;
    }
    else{
        c = a;
        a = b;
        b = c;
        c = a;
    }
    while (c % b != 0){
        c += a;
    }
    cout << c << endl;
    return 0;
    
}