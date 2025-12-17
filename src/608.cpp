#include <iostream>

using std::cout;
using std::endl;
using  std::cin;

class A {
        private:
                int x, y;
        protected:
                int area = -1, len = -1;
                A(int a, int b) : x(a), y(b) {
                }
        public:
                // ____qcodep____
                void calculate_area(){
                    area = x * y;
                }
                void calculate_len(){
                    len = (x + y) * 2;
                }


};

// class B : ____qcodep____ A {
//         ____qcodep____
// };

class B : public A{
public:
    B(int a, int b) : A(a, b) {
        calculate_area();
        calculate_len();
    }
    int getArea(){
        return area;
    }
    int getLen(){
        return len;
    }
};

int main() {
        int x, y;
        cin >> x >> y;
        B b(x, y);
        cout << b.getArea() << endl; // 200
        cout << b.getLen() << endl; // 60
        return 0;
}
