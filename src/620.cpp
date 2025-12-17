#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostringstream;
using std::ios_base;

// add other functions or "using" if necessary below. otherwise, leave it blank.

// ____qcodep____
bool check(char c){
    if(!(c >= 'a' && c <= 'z'))return true;
    return false;
}

string func(string &str) {
	// ____qcodep____
    ostringstream outstr;
    int idx = 0;
    while (idx < str.length() && check(str[idx]))
    {
        idx++;
    }
    for(; idx < str.length(); idx++){
        if(check(str[idx]))outstr << ' ';
        else outstr << str[idx];
    }

    return outstr.str();
}

int main() {
	int n;
	string str;
	cin >> n;
	cin.get();
	for (int i = 0; i < n; i++) {
		std::getline(cin, str);
		cout << func(str) << endl;
	}
	return 0;
}


