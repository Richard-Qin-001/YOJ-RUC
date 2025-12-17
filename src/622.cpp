#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

namespace {
	int CountGet = 0;
}

// put your code below for template functions Get and PutAndGet

// ____qcodep____
template <typename T>
void Get(T&tmp){
    cin >> tmp;
    CountGet++;
}

template <typename T>
void GetAndPut(int n){
    T val;
    for(int i = 0; i < n; ++i){
        Get(val);
        cout << val << (i == n - 1 ? "" : " ");
    }
    cout << endl;
    
}

int main() {
	int m, n;
	string tag;
	Get(m);
	Get(n);

	for(int i = 0; i < m; i++) {
		Get(tag);
		if (tag == "int") {
			GetAndPut<int>(n);
		} else if (tag == "double") {
			GetAndPut<double>(n);
		} else if (tag == "string") {
			GetAndPut<string>(n);
		}
	}
	cout << "Count of Get() = " << CountGet << endl;

	return 0;
}

