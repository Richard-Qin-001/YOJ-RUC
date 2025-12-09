#include <bits/stdc++.h>
using namespace std;

void solve(){
    string pswd;
    cin >> pswd;
    bool condition_1 = false, condition_2 = false, condition_3 = false, condition_4 = true;
    int len = pswd.length();
    unordered_map<char, int> freq;
    for(int i = 0; i < len; ++i){
        char c = pswd[i];
        if(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))condition_1 = true;
        if('0' <= c && c <= '9')condition_2 = true;
        if(c == '#' || c == '*')condition_3 = true;
        freq[c]++;
        if(freq[c] > 2)condition_4 = false;
    }
    if(condition_1 && condition_2 && condition_3 && condition_4)cout << 2 << endl;
    else if(condition_1 && condition_2 && condition_3)cout << 1 << endl;
    else cout << 0 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        solve();
    }
    return 0;
}