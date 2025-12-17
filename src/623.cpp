#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

namespace {
	int CountGet = 0;
}

class Node {
public:
	int x;
	double y;
};

std::istream& operator>>(std::istream& in, Node& node) {
	cout << "Should Not Enter Here" << endl;
	return in;
}

// ____qcodep____
template<typename T>
void Get(T&val){
    cin >> val;
    CountGet++;
}

template<typename T>
void GetAndPut(int n){
    T val;
    for(int i = 0; i < n; ++i){
        Get(val);
        cout << val << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

void Get(Node&node){
    CountGet++;
    Get(node.x);
    Get(node.y);
}
template<>
void GetAndPut<Node>(int n){
    Node node;
    for(int i = 0; i < n; ++i){
        Get(node);
        cout << node.x << " " << node.y << (i == n - 1 ? "" : " ");
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
		} else if (tag == "node") {
			GetAndPut<Node>(n);
		}
	}
	cout << "Count of Get() = " << CountGet << endl;

	return 0;
}

