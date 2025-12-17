#include <iostream>

using std::cout;
using std::endl;
using std::cin;

namespace {
    int g = 10;
}

// namespace ____qcodep____ {
namespace myns{

    int g = 20;

// ____qcodep____
    int add(int x){
        return ::g + myns::g + x;
    }

    int sub(int y){
        return ::g + myns::g -y;
    }

}

int main() {
        int x, y;
        cin >> x >> y;
        int a = myns::add(x);
        cout << a << endl;
        int b = myns::sub(y);
        cout << b << endl; 
        return 0;
}
