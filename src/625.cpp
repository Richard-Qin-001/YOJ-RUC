#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

template<typename T>
class Player {
protected:
	T data;
public:
	Player(T& t) : data(t) {}

	// ____qcodep____
    ~Player(){}
    void shuffle(){
        cout << "Player shuffles with " << data << ",";
    }
    template <typename U>
    void picker(U t){
        cout << " picks " << t << endl;
    }
};

// other declarations and implementations
// In Winner, use this->data, instead of "data".
// ____qcodep____
template <typename T1, typename T2>
class Winner : public Player<T1>
{
private:
    T2 data2;
public:
    Winner(T1 t1, T2 t2) : Player<T1>(t1), data2(t2) {};
    ~Winner(){};
    void shuffle(){
        cout << "Winner shuffles with " << this->data << " and " << this->data2 << ",";
    }
    template <typename U>
    void picker(U t){
        cout << " picks " << t << endl;
    }
};



//put the declaration of "dump" below
// ____qcodep____
template <typename P>
void dump(P& player){
    string tag;
	player.shuffle();
	cin >> tag;
	if (tag == "string") {
		cin >> tag;
		player.picker(tag);
	} else if (tag == "int") {
		int i32;
		cin >> i32;
		player.picker(i32);
	} else if (tag == "double") {
		double d64;
		cin >> d64;
		player.picker(d64);
	}
}

int main() {
	int n;
	string tag;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tag;
		if (tag == "player") {
			cin >> tag;
			if (tag == "int") {
				int data1;
				cin >> data1;
				Player<int> player(data1);
				dump(player);
			} else if (tag == "string") {
				string data1;
				cin >> data1;
				Player<string> player(data1);
				dump(player);
			} else if (tag == "double") {
				double data1;
				cin >> data1;
				Player<double> player(data1);
				dump(player);
			}
		} else if (tag == "winner") {
			string tag2;
			cin >> tag >> tag2;
			if (tag == "int" && tag2 == "int") {
				int data1, data2;
				cin >> data1 >> data2;
				Winner<int, int> winner(data1, data2);
				dump(winner);
			} else if (tag == "int" && tag2 == "string") {
				int data1;
				string data2;
				cin >> data1 >> data2;
				Winner<decltype(data1), decltype(data2)> winner(data1, data2);
				dump(winner);
			} else if (tag == "int" && tag2 == "double") {
				int data1;
				double data2;
				cin >> data1 >> data2;
				Winner<decltype(data1), decltype(data2)> winner(data1, data2);
				dump(winner);
			} else if (tag == "string" && tag2 == "string") {
				string data1;
				string data2;
				cin >> data1 >> data2;
				Winner<decltype(data1), decltype(data2)> winner(data1, data2);
				dump(winner);
			} else if (tag == "string" && tag2 == "int") {
				string data1;
				int data2;
				cin >> data1 >> data2;
				Winner<decltype(data1), decltype(data2)> winner(data1, data2);
				dump(winner);
			} else if (tag == "string" && tag2 == "double") {
				string data1;
				double data2;
				cin >> data1 >> data2;
				Winner<decltype(data1), decltype(data2)> winner(data1, data2);
				dump(winner);
			} else if (tag == "double" && tag2 == "double") {
				double data1;
				double data2;
				cin >> data1 >> data2;
				Winner<decltype(data1), decltype(data2)> winner(data1, data2);
				dump(winner);
			} else if (tag == "double" && tag2 == "string") {
				double data1;
				string data2;
				cin >> data1 >> data2;
				Winner<decltype(data1), decltype(data2)> winner(data1, data2);
				dump(winner);
			} else if (tag == "double" && tag2 == "int") {
				double data1;
				int data2;
				cin >> data1 >> data2;
				Winner<decltype(data1), decltype(data2)> winner(data1, data2);
				dump(winner);
			}
		}
	}
}

