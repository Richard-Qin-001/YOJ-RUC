#include <iostream>
#include <regex>
using namespace std;

bool is_integer(const string& s){
    static const regex re_int("[-+]?[0-9]+");
    return regex_match(s, re_int);
}
bool is_double(const string& s){
    static const regex re_double("[-+]?(?:[0-9]+\\.[0-9]*|[0-9]*\\.[0-9]+)([eE][-+]?[0-9]+)?");
    return regex_match(s, re_double);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    getline(cin, str);
    stringstream ss(str);
    int count_int = 0, count_double = 0;
    string num;
    while(ss >> num){
        if(is_double(num))count_double++;
        else if(is_integer(num)) count_int++;
    }
    cout << count_int << " " << count_double << endl;
    return 0;
}