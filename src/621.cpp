#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostringstream;
using std::istringstream;
using std::ios_base;



string str2hexint(string &str) {
	ostringstream outstr;

	// ____qcodep____
    istringstream instr(str);
    int val;
    bool first = true;
    while (instr >> val)
    {
        if(!first)outstr << " ";
        outstr << "0x" << std::hex << val;
        first = false;
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
		cout << str2hexint(str) << endl;
	}
	return 0;
}


