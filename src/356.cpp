#include <iostream>
using namespace std;

class Datatype {
public:
    void print();
    // ____qcodep____
    Datatype(char c) : _vartype(character), _c(c){}
    Datatype(int i) : _vartype(integer), _i(i){}
    Datatype(float f) : _vartype(floating), _f(f){}
private:
    enum Type
    {
        character,
        integer,
        floating
    } _vartype;

    union {
        char _c;
        int _i;
        float _f;
    };
};

void Datatype::print() {
    switch (_vartype) {
    case character:
        cout << "char: " << _c << endl;
        break;
    case integer:
        cout << "int: " << _i << endl;
        break;
    case floating:
        cout << "float: " << _f << endl;
        break;
    }
}

int main() {
    char c;
    int i;
    float f;
    cin >> c >> i >> f;
    Datatype ii(i), cc(c), ff(f);
    if(8 == sizeof(ii) &&
       8 == sizeof(cc) &&
       8 == sizeof(ff) ) {
        cc.print();
        ii.print();
        ff.print();       
    }
    return 0;
}