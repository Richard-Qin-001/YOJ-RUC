#include <iostream>
#include <string>
#include <vector>

using namespace std;

int str2int(string s){
    int len = s.length();
    int result = 0;
    for(int i = 0; i < len ;i ++){
        result = result * 10 + s[i] - '0';
    }
    return result;
}

void solve(){
    string s;
    cin >> s;
    int total = str2int(s);
    int a, b, c;
    if (total % 12 == 0) a = total / 12;
    else a = total / 12 + 1;
    total %= 12;
    // cout << a << endl;
    // cout << total << endl;
    if (total == 0){
        b = 6;
        c = 2;
    }
    else
    {
        if (total % 2 == 0) b = total / 2;
        else b = total / 2 + 1;
        if (total % 2 == 0) c = 2;
        else c = 1; 
    }
    
    string result = "";
    result += to_string(a);
    result += "-";
    result += to_string(b);
    result += "0";
    result += to_string(c);
    cout << result << endl;

}
int main(){solve(); return 0;}