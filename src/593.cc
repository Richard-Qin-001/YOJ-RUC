#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    int n;
    cin >> str >> n;
    int len = str.length();
    for(int i = 0; i < len; ++i)
    {
        str[i] = ((str[i] + n <= 'z') ? str[i] + n : str[i] + n - 26);
    }
    cout << str << endl;
    return 0;
}