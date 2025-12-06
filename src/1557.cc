#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    string result = str.back() + str.substr(0, str.size() - 1);
    cout << result << endl;
    return 0;
}