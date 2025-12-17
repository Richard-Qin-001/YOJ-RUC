#include <iostream>
#include <string>

// add the header file below
// ____qcodep____
#include <vector>

using namespace std;

// put you GetTo and Print implementation below
// ____qcodep____
template<typename T>
void GetTo(vector<T>&container){
    T temp;
    cin >> temp;
    container.emplace_back(temp);
}

template <typename T>
void Print(vector<T>&container)
{
    int n = container.size();
    for(int i = 0; i < n; ++i)cout << container[i] << (i != n-1 ? " " : "");
}

int main() {
	int n;
	string tag;
	cin >> n >> tag;
	if ("int" == tag) {
		// define the container with a proper container type
		// ____qcodep____
        vector<int> container;
		for (int i = 0; i < n; i++) {
			GetTo(container);
		}
		Print(container);
	} else if ("double" == tag) {
		// define the container with a proper container type
		// ____qcodep____
        vector<double> container;
		for (int i = 0; i < n; i++) {
			GetTo(container);
		}
		Print(container);
	}
	return 0;
}

