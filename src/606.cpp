#include <iostream>
#include <string>

namespace myns {
        class COUT {
                public:
                        COUT() {}
        };
        COUT cout;
}


class A {
        public:
                A(int x, int y) : w(x), h(y) {}
                int getLen() const {
                        if (len < 0) len = 2 * (w + h);
                        return len;
                }
        private:
// ____qcodep____
                int w;
                int h;
                mutable int len = -1;
        public:
                int getW() const {
                    return w;
                }
                int getH() const {
                    return h;
                }
};

// ____qcodep____
namespace myns {
    COUT& operator<<(COUT&out, const A&a){
        std::cout << "[" << a.getW() << "," << a.getH() << "] -> " << a.getLen();
        return out;
    }
    COUT& operator<<(COUT&out, const char* str){
        std::cout << str;
        return out;
    }
}

using myns::cout;
using std::cin;
int main() {
        int x, y;
        cin>>x>>y;
        A a1(x, y);
        cout << a1 << "\n";
        cin>>x>>y;
        A a2(x, y);
        cout << a2 << "\n";
        return 0;
}