#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> results;
string curr;

void generateParentheses(int leftUsed, int rightUsed){
    if(curr.length() == 2 * n){
        results.push_back(curr);
        return;
    }

    if(leftUsed < n){
        curr += '(';
        generateParentheses(leftUsed + 1, rightUsed);
        curr.pop_back();
    }
    if(rightUsed < leftUsed){
        curr += ')';
        generateParentheses(leftUsed, rightUsed + 1);
        curr.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    generateParentheses(0, 0);
    int sz = results.size();
    cout << sz << endl;
    for(int i = 0; i < sz; ++i)cout << results[i] << "\n";
    return 0;
}