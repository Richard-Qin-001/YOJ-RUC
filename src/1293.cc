#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string pattern, formulasLine;
    getline(cin, pattern);
    getline(cin, formulasLine);

    stringstream ss(formulasLine);
    vector<string> formulas;
    string tmp;
    while (ss >> tmp)
    {
        formulas.push_back(tmp);
    }
    
    string result = "";
    for (char c : pattern) {
        if (c >= 'A' && c <= 'Z') {
            int idx = c - 'A';
            result += formulas[idx];
        } else {
            result += c;
        }
    }
    cout << result << endl;
    return 0;

}