#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    array<int, 26> count_proposition{0};
    array<int, 5> count_op{0};
    string op_chars = "!&|>-";

    for (char c : s){
        if (c >= 'a' && c <= 'z'){
            count_proposition[c - 'a']++;
        } else {
            for (int i = 0; i < 5; ++i){
                if (c == op_chars[i]){
                    count_op[i]++;
                    break;
                }
            }
        }
    }

    bool first = true;
    for (int i = 0; i < 26; ++i) {
        if (count_proposition[i] > 0){
            cout << (first ? "" : " ");
            cout << count_proposition[i] << static_cast<char>('a' + i);
            first = false;
        }
    }
    cout << endl;

    first = true;
    for (int i = 0; i < 5; ++i) {
        if (count_op[i] > 0) {
            cout << (first ? "" : " ");
            cout << count_op[i] << op_chars[i];
            first = false;
        }
    }
    cout << endl;
    return 0;
}