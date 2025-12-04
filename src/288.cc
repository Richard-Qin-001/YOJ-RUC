#include <bits/stdc++.h>
using namespace std;

int compare(const string& s1, const string& s2){
    if(s1 == s2)return 0;
    int len1 = s1.length(), len2 = s2.length();
    for(int i = 0; i < len1 && i < len2; ++i){
        if(s1[i] != s2[i])return s1[i] - s2[i];
    }
    return 0;
}

int main(){
    string s1, s2;
    getline(cin, s1);
    // cin.ignore(1, "\n");
    getline(cin, s2);
    int result = compare(s1, s2);
    cout << result << endl;
    return 0;
}