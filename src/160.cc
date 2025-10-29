#include <iostream>
#include <cstring>

using namespace std;

void move(string&s){
    s.push_back(s.front());
    s.erase(0, 1);
}

void solve(){
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    for(int i = 0; i < n; i++){
        if(s1.find(s2) != string::npos){
            cout << "true" << endl;
            return;
        }
        move(s1);
        // cout << s1 << endl;
    }
    cout << "false" << endl;
}
int main(){solve();return 0;}