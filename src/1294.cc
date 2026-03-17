#include <bits/stdc++.h>
using namespace std;

string process_minterm (string term) {
    int value = 0;
    stringstream ss(term);
    string literal;

    while (getline(ss, literal, '&'))
    {
        value <<= 1;
        if (literal.find('!') != string::npos) {
            value |= 0;
        } else {
            value |=1;
        }
    }
    return "m" + to_string(value);
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string pdnf, result = "";
    cin >> pdnf;

    stringstream ss(pdnf);
    string term;
    while (getline(ss, term, '|'))
    {
        result += process_minterm(term) + '|';
    }
    result.pop_back();
    
    cout << result << endl;
    return 0;
}