#include <bits/stdc++.h>
using namespace std;

void process(string&word){
    int len = word.length();
    for(int i = 0; i < len; ++i)if(word[i] <= 'Z')word[i] = word[i] + 32;
}

int main(){
    int n, m;
    cin >> n >> m;
    map<string, int> a, b, c;
    string word;
    for(int i = 0; i < n; ++i){
        cin >> word;
        process(word);
        a[word]++;
        c[word]++;
    }
    for(int j = 0; j < m; ++j){
        cin >> word;
        process(word);
        b[word]++;
        c[word]++;
    }
    int x = 0, y = 0;
    for(auto&w:a){
        b[w.first]++;
        if(b.at(w.first)!=1)x++;
    }
    y = c.size();
    cout << x << '\n' << y << endl;
    return 0;
}