#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostringstream;
using std::ios_base;

string space2nl(string &str) {
	ostringstream outstr;
	
	// ____qcodep____
    for(char&c:str){
        if(c == ' ')outstr << '\n';
        else outstr << c;
    }

	return outstr.str();
}

int main() {
	int n;
	string str;
	cin >> n;
	cin.get(); // be careful on Windows. Duplicate this line if necessary in testing
	for (int i = 0; i < n; i++) {
		std::getline(cin, str);
		// Be careful: NO endl at the end of the output below
		cout << space2nl(str);
	}
	return 0;
}


