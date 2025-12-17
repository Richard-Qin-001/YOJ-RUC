#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

class Node {
public:
	int x;
	double y;
};

// put the declaration of Triplet below
// ____qcodep____

template<typename T1, typename T2, typename T3>
class Triplet{
public:
    T1 val1;
    T2 val2;
    T3 val3;
};

std::istream& operator>>(std::istream& in, Node& node) {
	cout << "Should Not Enter Here" << endl;
	return in;
}

template<typename T1, typename T2, typename T3>
std::istream& operator>>(std::istream& in, Triplet<T1, T2, T3>& triplet) {
	cout << "Should Not Enter Here" << endl;
	return in;
}

// put the other code below
// ____qcodep____
template <typename T>
void Get(T &val){
    cin >> val;
}

void Get(Node &node){
    Get(node.x);
    Get(node.y);
}

template <typename T1, typename T2, typename T3>
void Get(Triplet<T1, T2, T3> &triplet){
    Get(triplet.val1);
    Get(triplet.val2);
    Get(triplet.val3);
}

template <typename T>
void Put(const T &val){
    cout << val;
}

void Put(const Node &node)
{
    Put(node.x);
    cout << " ";
    Put(node.y);
}

template <typename T1, typename T2, typename T3>
void Put(const Triplet<T1, T2, T3> &t){
    Put(t.val1);
    cout << " ";
    Put(t.val2);
    cout << " ";
    Put(t.val3);
}

template <typename T>
void GetAndPut(int n){
    T val;
    for (int i = 0; i < n; ++i){
        Get(val);
        Put(val);
        cout << (i != n - 1 ? " " : "");
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
		} else if (tag == "triplet") {
			string tr1, tr2;
			Get(tr1);
			Get(tr2);
			if (tr1 == "int" && tr2 == "node") {
				// call GetAndPut below
				// ____qcodep____
                GetAndPut<Triplet<int, int, double>>(n);
            } else if (tr1 == "int" && tr2 == "any") {
				// call GetAndPut below
				// ____qcodep____
                GetAndPut<Triplet<int, string, string>>(n);
            } else if (tr1 == "node" && tr2 == "int") {
				// call GetAndPut below
				// ____qcodep____
                GetAndPut<Triplet<int, double, int>>(n);
            } else if (tr1 == "any" && tr2 == "any") {
				// call GetAndPut below
				// ____qcodep____
                GetAndPut<Triplet<string, string, string>>(n);
            } else if (tr1 == "node" && tr2 == "any") {
				// call GetAndPut below
				// ____qcodep____
                GetAndPut<Triplet<int, double, string>>(n);
            }
		}
	}

	return 0;
}

