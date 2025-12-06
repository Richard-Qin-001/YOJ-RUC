#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;
    int a, b, n;
    for(int i = 0; i < k; ++i){
        cin >> a >> b >> n;
        double z = (double)(n - a) / (double)b;
        string str = to_string(z);
        size_t pos = str.find('.');
        // cout << str << endl;
        string s1 = str.substr(0, pos + 2), s2 = str.substr(pos + 2, 1);
        s1.erase(pos, 1);
        // cout << s1 << " " << s2 << endl;
        cout << stoi(s1) + 1 << " " << stoi(s2) + 1 << endl;
    }
    return 0;
}