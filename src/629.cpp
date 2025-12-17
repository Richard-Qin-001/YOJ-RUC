#include <iostream>
#include <string>

// add the header file below
// ____qcodep____
#include <set>

using namespace std;

// put you GetTo and Print implementation below
// ____qcodep____
template <typename T>
void GetTo(multiset<T>&container){
    T temp;
    cin >> temp;
    container.insert(temp);
}
template <typename T>
void Print(multiset<T>&container){
    for (auto it = container.begin(); it != container.end(); ++it){
        cout << *it << (next(it) == container.end() ? "" : " ");
    }
}
int main() {
	int n;
	string tag;
	cin >> n >> tag;
	if ("int" == tag) {
		// define the container with a proper container type
		// ____qcodep____
        multiset<int> container;
		for (int i = 0; i < n; i++) {
			GetTo(container);
		}
		Print(container);
	} else if ("double" == tag) {
		// define the container with a proper container type
        // ____qcodep____ 
        multiset<double> container;
        for (int i = 0; i < n; i++) {
			GetTo(container);
		}
		Print(container);
	}
	return 0;
}

