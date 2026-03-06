#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ____qcodep____
template<typename T>
class Stack {
private:
    vector<T> stack;

public:
void push(T val){
    stack.push_back(val);
}

T pop(){
    T tmp = stack.back();
    stack.pop_back();
    return tmp;
}

};


int main()
{
	Stack<int> intStack;
	Stack<string> stringStack;
	for (int i = 0; i < 3; i++)
	{
		int x;
		string s;
		cin >> x;
		cin >> s;
		intStack.push(x);
		stringStack.push(s);
	}
	for (int i = 0; i < 3; i++)
	{
		cout << intStack.pop() << " " << stringStack.pop() << endl;
	}
	return 0;
}