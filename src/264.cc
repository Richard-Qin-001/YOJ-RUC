#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, rows;
    string command;
    vector<string> article;
    cin >> n;
    cin >> command >> rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for(int i = 0; i < n; i++){
        string line;
        getline(cin, line);
        article.push_back(line);
        line.clear();
    }
    if(command == "head")for(int i = 0; i < rows; i++)cout << article[i] << endl;
    if(command == "tail")for(int i = n-rows; i < n; i++)cout << article[i] << endl;
}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}