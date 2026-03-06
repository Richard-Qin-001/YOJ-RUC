#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// ____qcodep____
class Object {

public:
    virtual void say_hello(const char *words);
    virtual ~Object();
};

class Some : public Object {
public:
	void say_hello(const char * words);
	~Some();
};

// ____qcodep____

Object::~Object(){
    cout << "(Object ends)" << "\n";
}

void Object::say_hello(const char *words)
{
    cout << "(Object says): " << words << "\n";
}

Some::~Some()
{
    cout << "(Some ends)" << "\n";
}

void Some::say_hello(const char *words)
{
    cout << "(Some says): " << words << "\n";
}

void say_hello(Object * obj, const char * words) {
	obj->say_hello(words);
}

void say_hello(Object obj, const char * words) {
	obj.say_hello(words);
}

int main() {
	int n;
	int mode;
	char words[20];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> mode >> words;
		if (mode > 0) {
			Some some;
			if (mode % 2) {
				say_hello(some, words);
			} else {
				say_hello(&some, words);
			}
		} else {
			Object obj;
			if (mode < -100) {
				say_hello(&obj, words);
			} else {
				say_hello(obj, words);
			}

		}
	}
	return 0;
}