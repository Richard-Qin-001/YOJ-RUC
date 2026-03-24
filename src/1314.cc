#include <bits/stdc++.h>
using namespace std;

string strip(string s)
{
    if (s.length() >= 2 && s.front() == '(' && s.back() == ')')
    {
        return s.substr(1, s.length() - 2);
    }
    return s;
}

struct SplitInfo
{
    string left, right;
    char op = ' ';
};

SplitInfo splitByOp(string s)
{
    int level = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '(')
            level++;
        else if (s[i] == ')')
            level--;
        else if (level == 0)
        {
            if (s[i] == '>' || s[i] == '|' || s[i] == '-')
            {
                return {s.substr(0, i), s.substr(i + 1), s[i]};
            }
        }
    }
    return {"", "", ' '};
}

vector<string> splitByAnd(string s)
{
    vector<string> res;
    int level = 0, start = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '(')
            level++;
        else if (s[i] == ')')
            level--;
        else if (s[i] == '&' && level == 0)
        {
            res.push_back(s.substr(start, i - start));
            start = i + 1;
        }
    }
    res.push_back(s.substr(start));
    return res;
}



int main() {
    string s;
    cin >> s;

    vector<string> parts = splitByAnd(s);

    if (parts.size() == 2) {
        string p1_inner = strip(parts[0]);
        SplitInfo info1 = splitByOp(p1_inner);

        if (info1.op == ' ' || info1.left[0] != '(')
        {
            cout << parts[0] << endl;
        }
        else
        {
            string A = strip(info1.left);
            string B = strip(info1.right);

            if (info1.op == '>')
            {
                if (parts[1][0] == '!')
                {
                    cout << "!(" << A << ")" << endl;
                }
                else
                {
                    string p2_inner = strip(parts[1]);
                    if (p2_inner == A)
                    {
                        cout << "(" << B << ")" << endl;
                        return 0;
                    }
                    SplitInfo info2 = splitByOp(p2_inner);
                    if (info2.op == '>')
                    {
                        string C = strip(info2.right);
                        cout << "(" << A << ")>(" << C << ")" << endl;
                    }
                    else
                    {
                        cout << "(" << B << ")" << endl;
                    }
                }
            }
            else if (info1.op == '|')
            {
                cout << "(" << A << ")" << endl;
            }
            else if (info1.op == '-')
            {
                string p2_inner = strip(parts[1]);
                SplitInfo info2 = splitByOp(p2_inner);
                string C = strip(info2.right);
                cout << "(" << A << ")-(" << C << ")" << endl;
            }
        }
    } else if (parts.size() == 3) {
        SplitInfo info1 = splitByOp(strip(parts[0])); // (A)>(B)
        SplitInfo info2 = splitByOp(strip(parts[1])); // (C)>(D)
        string A = strip(info1.left), B = strip(info1.right);
        string C = strip(info2.left), D = strip(info2.right);

        string p3_inner = strip(parts[2]);
        SplitInfo info3 = splitByOp(p3_inner);

        if (info3.left[0] == '!')
        { 
            cout << "!(" << A << ")|!(" << C << ")" << endl;
        }
        else
        {
            cout << "(" << B << ")|(" << D << ")" << endl;
        }
    } 
    return 0;
}