# include <iostream>
using namespace std;

int main(){
    char ch;
    cin >> ch;
    int int_ch = (int)ch;
    if ((int)ch >= (int)'a' && (int)ch <= 'z'){
        int_ch = int_ch - 32;
        cout << char(int_ch) << endl;
    }
    else{
        int_ch = int_ch + 32;
        cout << char(int_ch) << endl;
    }
    return 0;
}