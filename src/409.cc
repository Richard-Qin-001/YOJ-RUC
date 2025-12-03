#include <bits/stdc++.h>
using namespace std;

int main(){
    string sentence;
    getline(cin, sentence);
    vector<string> words;
    stringstream ss(sentence);
    string word;
    while (ss >> word)words.push_back(word);
    int total = words.size();
    string solution;
    int max_len = 0;
    for(int i = 0; i < total; ++i){
        int current_len = words[i].length();
        for(int j = 0; j < current_len; j++)if(words[i][j] == 'a' || words[i][j] == 'A')if(current_len > max_len){solution = words[i]; max_len =current_len;}
    }
    if(solution.empty()){
        cout << -1 << endl;
        return 0;
    }
    cout << solution << endl;
    return 0;
}