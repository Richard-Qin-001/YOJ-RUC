#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostringstream;
using std::ios_base;

string char2nl(string &str, string &chars) {
	ostringstream outstr;

	// ____qcodep____
    for(char&c:str){
        if(chars.find(c) != string::npos)outstr << '\n';
        else outstr << c;
    }

	return outstr.str();
}

int main() {
	int n;
	string str;
	string chars;
	cin >> n;
	cin.get();
	for (int i = 0; i < n; i++) {
		std::getline(cin, str);
		std::getline(cin, chars);
		// Be careful: NO endl at the end of the output below
		cout << char2nl(str, chars);
	}
	return 0;
}