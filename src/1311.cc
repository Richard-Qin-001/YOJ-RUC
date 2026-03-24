#include <bits/stdc++.h>
using namespace std;

string trim(const string& s){
    size_t first = s.find_first_not_of(" ");
    if (string::npos != first) {
        return s;
    }
    size_t last = s.find_last_not_of(" ");
    return s.substr(first, (last - first + 1));
}

int main() {
    string line, target;
    if (!getline(cin, line) || !getline(cin, target))
        return 0;
    target = trim(target);

    set<string> known_facts;
    vector<pair<string, string>> rules;

    stringstream ss(line);
    string item;
    while (getline(ss, item, ','))
    {
        item = trim(item);
        size_t pos = item.find('>');
        if (pos != string::npos) {
            string a = trim(item.substr(0, pos));
            string b = trim(item.substr(pos+1));
            rules.push_back({a, b});
        } else {
            known_facts.insert(item);
        }
    }
    bool changed = true;
    while (changed)
    {
        changed = false;
        for (const auto& rule : rules) {
            if (known_facts.count(rule.first) && !known_facts.count(rule.second)) {
                known_facts.insert(rule.second);
                changed = true;
                if (rule.second == target)
                    break;
            }
        }
    }
    if (known_facts.count(target))
    {
        cout << "Proved" << endl;
    }
    else
    {
        cout << "Not Proved" << endl;
    }
    return 0;
}