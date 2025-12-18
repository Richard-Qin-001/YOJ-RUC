#include <iostream>
#include <string.h>
#include <memory.h>

using std::cout;
using std::endl;
using std::cin;

class Object {
public:
    Object() {
        name = new char[20];
    }
    Object(const Object & obj) {
        cout << "Should not enter this function" << endl;
    }

protected:
    char *name;
    
public:

// ____qcodep____
    virtual ~Object(){
        if (name) {
            cout << "dtor in Object (" << name << ")" << endl;
            delete[] name;
        }
    }
    virtual void dump() const {
        cout << name << endl;
    }

};

class Some : public Object {
private:
    char *affil;
public:
    Some(const char * _n, const char *_a) {
        strcpy(name, _n);
        affil = new char[20];
        strcpy(affil, _a);
    }
// ____qcodep____

    ~Some(){
        if (affil){
            cout << "dtor in Some (" << affil << ")" << endl;
            delete[] affil;
        }
    }
    void dump() const override {
        cout << name << " in " << affil << endl;
    }

};

bool func(const Object & obj) {
    obj.dump();
    return false;
}

bool func(const Object * obj, int mode) {
    obj->dump();
    if (mode % 2) {
        delete obj;
        return true;
    }
    return false;
}

int main() {
    int n;
    char name[20];
    char affil[20];
    int mode;
    Object **objects;
    cin >> n;
    objects = new Object*[n];
    for (int i = 0; i < n; i++) {
        cin >> name >> affil >> mode;
        Some *some = new Some(name, affil);
        memset(name, 0, 20);
        memset(affil, 0, 20);
        if(mode) {
            if (!func(some, mode)) {
                objects[i] = some;
            } else {
                objects[i] = nullptr;
            }
        } else {
            func(*some);
            objects[i] = some;
        }
    }
    for (int i = 0; i < n; i++) {
        delete objects[i];
    }
    delete[] objects;
    return 0;
}

