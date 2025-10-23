#include <iostream>
#include <cstring>

using namespace std;

int ch2int(char n){
    int result = (int)n - 48;
    return result;
}

char int2ch(int n){
    char result = char(n + 48);
    return result;
}

void strrvs(string& str){
    size_t len = str.size();
    for (size_t i =0; i < len/2; i++){
        swap(str[i], str[len-i-1]);
    }
}

string splus(string a, string b){
    size_t la = a.size(); 
    size_t lb = b.size();
    string result;
    strrvs(a);
    strrvs(b);
    if (la < lb){
        a.resize(lb);
        for (size_t i = la; i < lb; i++){
            a[i] = '0';
        }
    }
    else if (la > lb){
        b.resize(la);
        for (size_t i = lb; i < la; i++){
            b[i] = '0';
        }
    }
    int z = 0;
    for (size_t i = 0; i < max(la, lb); i++){
        int x = ch2int(a[i]);
        int y = ch2int(b[i]);
        int sum = x + y + z;
        int k = sum % 10;
        z = sum / 10;
        result.push_back(int2ch(k));

    }
    if (z != 0){
        result.push_back(int2ch(z));
    }
    strrvs(result);
    return result;

}

string sminus(string a, string b){
    size_t la = a.size(); 
    size_t lb = b.size();
    string result;
    strrvs(a);
    strrvs(b);
       
    if (lb < la) {
    b.resize(la, '0');
    }
    
    int z = 0;
    for (size_t i = 0; i < max(la, lb); i++){
        int x = ch2int(a[i]) + z;
        int y = ch2int(b[i]);
        z = 0;
        if (x >= y){
        result.push_back(int2ch(x - y));
        } else {
        result.push_back(int2ch(x + 10 - y));
        z = -1;
        }
    }
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }
    
    strrvs(result);
    if (result.empty() || result == "0") {
        return "0";
    }
    return result;

}

int judge(string& a, string& b){
    size_t la = a.size();
    size_t lb= b.size();
    if (la > lb) return 1;
    else if (la < lb) return 0;
    else {
        for (size_t i = 0; i < la; i++){
            if (ch2int(a[i]) > ch2int(b[i])) return 1;
            else if (ch2int(a[i]) < ch2int(b[i])) return 0;
        }
    }
    return -1;

}

void solve(){
    char ch;
    cin >> ch;
    string in_a, in_b;
    string a, b;
    string result;
    string tmp;
    cin >> in_a >> in_b;
    if (ch == '+'){
        if (in_a[0] != '-' && in_b[0] != '-'){
            a = in_a;
            b = in_b;
            result = splus(a, b);
        }
        else if (in_a[0] == '-' && in_b[0] != '-'){
            a = in_a.substr(1);
            b = in_b;
            if (judge(a,b) == 1) {
                tmp = sminus(a, b);
                result = '-' + tmp;
            
            }
            else if(judge(a,b) == 0){
                result = sminus(b, a);
            }
            else result = '0';
            
        }
        else if (in_a[0] != '-' && in_b[0] == '-'){
            a = in_a;
            b = in_b.substr(1);
            if (judge(a,b) == 0) {
                tmp = sminus(b, a);
                result = '-' + tmp;
            }
            
            
            else if(judge(a,b) == 1){
                result = sminus(a, b);
            }
            else result = '0';
        }
        
        else {
            a = in_a.substr(1);
            b = in_b.substr(1);
            tmp = splus(a,b);
            result = '-' + tmp;

        }
    }
    else{

        if (in_a[0] != '-' && in_b[0] == '-'){// (+) - (-)
            a = in_a;
            b = in_b.substr(1);
            result = splus(a, b);
        }
        else if (in_a[0] != '-' && in_b[0] != '-'){
            a = in_a;
            b = in_b;
            if (judge(a,b) == 1) {
                result = sminus(a, b);
            }
            else if(judge(a,b) == 0){
                tmp = sminus(b, a);
                result = '-' + tmp;
            }
            else result = '0';
            
            }
        else if (in_a[0] == '-' && in_b[0] == '-'){
            a = in_a.substr(1);
            b = in_b.substr(1);
            if (judge(a,b) == 1) {
                tmp = sminus(a, b);
                result = '-' + tmp;
            
            }
            else if(judge(a,b) == 0){
                result = sminus(b, a);
            }
            else result = '0';
            
        }
        else { // (-) - (+)
            a = in_a.substr(1);
            b = in_b;
            tmp = splus(a,b);
            result = '-' + tmp;
        }
    }    
    cout << result;
}


int main(){solve(); return 0;}