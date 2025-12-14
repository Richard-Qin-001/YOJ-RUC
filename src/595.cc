#include <bits/stdc++.h>
using namespace std;

bool check(string str){
    int len = str.length();
    if (len == 0 || len > 3)
        return false;
    if(len == 1)return true;
    
    if (str[0] == '0') return false;
    int num = stoi(str);
    return num >= 1 && num <= 255;
}

int main(){
    string str;
    cin >> str;
    int len = str.length();
    for(int i = 1; i < 4; ++i){
        for(int j = i + 1; j < 7; ++j){
            for(int k = j + 1; k < len; ++k){
                string str1 = str.substr(0, i), str2 = str.substr(i, j - i), str3 = str.substr(j, k - j), str4 = str.substr(k);
                if(check(str1) && check(str2) && check(str3) && check(str4)){
                    cout << str1 + '.' + str2 + '.' + str3 + '.' + str4 << endl;
                }
            }
        }
    }
    return 0;
}