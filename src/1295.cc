#include <bits/stdc++.h>
using namespace std;

typedef set<string> Clause;

vector<Clause> parseCNF(string s){
    vector<Clause> clauses;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '(' || s[i] == ')' || s[i] == '&')
        {
            s[i] = ' ';
        }
    }
    stringstream ss(s);
    string clause_str;
    while (ss >> clause_str)
    {
        for (int i = 0; i < clause_str.length(); ++i)
        {
            if (clause_str[i] == '|')
            {
                clause_str[i] = ' ';
            }
        }
        stringstream ss2(clause_str);
        string literal;
        Clause currentClause;
        while (ss2 >> literal)
        {
            currentClause.insert(literal);
        }
        if (!currentClause.empty()) {
            clauses.push_back(currentClause);
        }
    }
    return clauses;
}

string negateLiteral(string lit)
{
    if (lit[0] == '!')
        return lit.substr(1);
    return "!" + lit;
}

pair<bool, Clause> resolve(Clause c1, Clause c2)
{
    int complementCount = 0;
    string targetLiteral = "";

    for (const string& lit : c1) {
        string neg = negateLiteral(lit);
        if (c2.count(neg)) {
            complementCount++;
            targetLiteral = lit;
        }
    }
    if (complementCount == 1)
    {
        Clause res = c1;
        res.erase(targetLiteral);
        for (const string &lit : c2)
        {
            if (lit != negateLiteral(targetLiteral))
            {
                res.insert(lit);
            }
        }
        return {true, res};
    }

    return {false, {}};
}

bool isTautology(const Clause &c)
{
    for (const string &lit : c)
    {
        if (c.count(negateLiteral(lit)))
            return true;
    }
    return false;
}

int main(){
    string line;
    getline(cin, line);
    vector<Clause> clauses = parseCNF(line);
    
    bool changed = true;
    while (changed)
    {
        changed = false;
        int n = clauses.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j){
                auto res = resolve(clauses[i], clauses[j]);
                if (res.first) {
                    Clause new_clause = res.second;
                    if (new_clause.empty())
                    {
                        cout << "no" << endl;
                        return 0;
                    }
                    if (!isTautology(new_clause)) {
                        bool exists = false;
                        for (const auto& c: clauses) {
                            if (c == new_clause)
                            {
                                exists = true;
                                break;
                            }

                        }
                        if (!exists) {
                            clauses.push_back(new_clause);
                            changed = true;
                        }

                    }
                }
            }
        }
    }
    cout << "yes" << endl;
    return 0;

}