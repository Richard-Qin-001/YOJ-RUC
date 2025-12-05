#include <bits/stdc++.h>
#include <string>
using namespace std;

int str2int(string num){
    int result = 0;
    int len = num.length();
    for(int i = 0; i < len; ++i){
        result = result * 10 + num[i] - '0';
    }
    return result;
}

int main(){
    string N;
    int K;
    cin >> N >> K;
    int len = N.length();
    int solutions = 0;
    for(int i = 0; i < len; i++){
        if(N[i] == 'X'){
            string str1 = N.substr(0, i);
            string str2 = N.substr(i+1);
            for(int j = 0; j < 10; ++j){
                string str3 = to_string(j);
                string num = str1 + str3 + str2;
                int n = str2int(num);
                if(n % K == 0 && n != 0)solutions++;
            }
        }
    }
    cout << solutions << endl;
    return 0;
}