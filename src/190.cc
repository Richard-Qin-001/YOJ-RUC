#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

char transform(char ch){
    if ((int)ch < 97) ch = char((int)ch + 32);
    return ch;
}

void solve(){
    string str;
    getline(cin, str);
    for(auto&c:str) c = transform(c);
    map<char, int> dict;
    for(auto&c:str) dict[c]++;
    vector<pair<char, int>> sorted_list(dict.begin(), dict.end());
    sort(
        sorted_list.begin(), sorted_list.end(),[](const pair<char, int>&a, const pair<char, int>&b){
            if(a.second != b.second) return a.second > b.second;
            else return a.first < b.first;
        }
    );
    for(auto&m:sorted_list) cout << m.first << " " << m.second << endl;
}

int main(){solve(); return 0;}