#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    getline(cin, str);
    int len = str.length();
    bool is_int = true, is_float = true, is_str = true;
    for(int i = 0; i < len; ++i){
        if(!((str[i] >= '0' && str[i] <= '9') || (i == 0 && str[0] == '-'))){
            is_int = false;
            break;
        }
    }
    if(is_int){
        int num = stoi(str);
        cout << (long long)num + 1 << endl;
        return 0;
    }
    for(int i = 0; i < len; ++i){
        if(!((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || (i == 0 && str[0] == '-'))){
            is_float = false;
            break;
        }
    }
    if(is_float){
        double num = stod(str);
        cout << (int)num << endl;
        return 0;
    }
    for(int i = 0; i < len; ++i){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] -= 32;
        }
    }
    cout << str << endl;
    return 0;
}