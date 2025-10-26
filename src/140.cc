#include <iostream>
#include <cstring>

using namespace std;

void find(const string&str, const string&prompt, string&info){
    size_t position = str.find(prompt);
    position += prompt.size();
    while(str[position] != ',' && str[position] != '.'){
        info += str[position];
        position++;
    }
}

void solve(){
    string str,birthday, major;
    string s1 = "My name is ", s2 = ", born in ", s3 = ", from ", s4 = ". My major is ", s5 = ". I like ";
    getline(cin, str);
    find(str, s2, birthday);
    find(str, s4, major);
    cout << birthday << ", " << major << endl;
}
int main(){solve(); return 0;}