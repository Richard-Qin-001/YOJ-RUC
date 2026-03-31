#include <bits/stdc++.h>
using namespace std;

set<char> bound_vars;

pair<string, string> split_args(const string& s) {
    int paren_count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            paren_count ++;
        } else if (s[i] == ')') {
            paren_count --;
        } else if (s[i] == ',' && paren_count == 0) {
            return {s.substr(0, i), s.substr(i + 1)};
        }
    }
    return {"", ""};
}

string parse_term(const string& s) {
    if (s == "a") {
        return "0";
    }

    if (s == "x") {
        return bound_vars.count('x') ? "x" : "1";
    }
    if (s == "y") {
        return bound_vars.count('y') ? "y" : "2";
    }
    if (s == "z") {
        return bound_vars.count('z') ? "z" : "3";
    }

    if (s.length() > 2 && s[0] == 'f' && s[1] == '(') {
        string inner = s.substr(2, s.length() - 3);
        auto args = split_args(inner);
        return parse_term(args.first) + "+" + parse_term(args.second);
    }

    if (s.length() > 2 && s[0] == 'g' && s[1] == '(') {
        string inner = s.substr(2, s.length() - 3);
        auto args = split_args(inner);
        return parse_term(args.first) + "*" + parse_term(args.second);
    }

    return "";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cin >> input;

    int first_paren = input.find('(');
    string prefix = input.substr(0, first_paren);
    string formula = input.substr(first_paren);

    for (int i = 0; i < prefix.length(); ++i)
    {
        if (prefix[i] == 'V' || prefix[i] == 'E')
        {
            if (i + 1 < prefix.length())
            {
                bound_vars.insert(prefix[i + 1]);
                i++;
            }
        }
    }
    string inner_F = formula.substr(3, formula.length() - 5);

    auto args = split_args(inner_F);
    string term1 = parse_term(args.first);
    string term2 = parse_term(args.second);

    cout << prefix << "(" << term1 << "=" << term2 << ")" << "\n";

    return 0;
}