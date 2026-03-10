#include <bits/stdc++.h>
using namespace std;

int get_precendence(char op){
    if (op == '!') return 5;
    if (op == '&') return 4;
    if (op == '|') return 3;
    if (op == '>') return 2;
    if (op == '-') return 1;
    return 0;
}

string infix_to_postfix(const string&s){
    string postfix = "";
    stack<char> ops;

    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            postfix += c;
        }
        else if (c == '(') {
            ops.push(c);

        } else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                postfix += ops.top();
                ops.pop();
            }
            if (!ops.empty() && ops.top() == '(')
            {
                ops.pop();
            }
        } else {
            while (!ops.empty() &&
                   (get_precendence(ops.top()) > get_precendence(c) ||
                    (get_precendence(ops.top()) == get_precendence(c) && c != '!')))
            {
                postfix += ops.top();
                ops.pop();
            }
            ops.push(c);
        }
    }

    while (!ops.empty())
    {
        postfix += ops.top();
        ops.pop();
    }
    return postfix;
}

bool evaluate_postfix(string postfix, array<int, 256> valMap){
    stack<bool> st;

    for (char c : postfix) {
        if (c >= 'a' && c <= 'z') { 
            st.push(valMap[c]);
        } else if (c == '!') {
            bool op = st.top();
            st.pop();
            st.push(!op);
        } else {
            bool right = st.top();
            st.pop();

            bool left = st.top();
            st.pop();

            if (c == '&') {
                st.push(left && right);
            } else if (c == '|') {
                st.push(left || right);
            } else if (c == '>') {
                st.push(!left || right);
            } else if (c == '-') {
                st.push(left == right);
            }
        }
    }
    return st.top();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    set<char> varChar;
    for (char c : s) {
        if (c >= 'a' && c <= 'z'){
            varChar.insert(c);
        }
    }
    vector<char> vars(varChar.begin(), varChar.end());
    int n = vars.size();

    string postfix = infix_to_postfix(s);

    for (char v : vars) {
        cout << v << " ";
    }
    cout << s << endl;

    int rows = 1 << n;
    for (int i = 0; i < rows; ++i) {
        array<int, 256> valMap{0};

        for (int j = 0; j < n; ++j) {
            bool val = (i >> (n - 1 - j)) & 1;
            valMap[vars[j]] = val;
            cout << val << " ";
        }

        bool result = evaluate_postfix(postfix, valMap);
        cout << result << endl;
    }
    return 0;
}  