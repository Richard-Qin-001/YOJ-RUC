#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class A {
        private:
                int x, y;
        protected:
                int area = -1, len = -1;
                A(int a, int b) : x(a), y(b) {
                }
                int getLen();
        public:
                int getArea();
                void resetXY() {
                	x = -1;
                	y = -1;
                }
};

// ____qcodep____
int A::getArea(){
    return area;
}
int A::getLen(){
    return len;
}

// class B : ____qcodep____  A {
//         ____qcodep____
// };

class B : public A {
public:
    B(int a, int b) : A(a, b){
        this->area = a * b;
        this->len = (a + b) * 2;
    }
    using A::getLen;

};

int main() {
        int x, y;
        cin >> x >> y;
        B b(x, y);
        cout << b.getArea() << endl; // 200
        cout << b.getLen() << endl; // 60
        b.resetXY();
        cout << b.getArea() << endl; // 200
        cout << b.getLen() << endl; // 60
        return 0;
}
