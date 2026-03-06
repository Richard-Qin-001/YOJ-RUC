#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class Object {
public:
    void fire(int value);
    
    // ____qcodep____
    virtual int onFocus() = 0;

};

// ____qcodep____
class Some : public Object {
private:
    int height_;
public:
    void setHeight(int value){
        this->height_ = value;
    }

    int onFocus() override {
        return this->height_ * 3;
    }
};

class Thing : public Object {
private:
    int weight_;
public:
    void setWeight(int value){
        this->weight_ = value;
        return void(0);
    }
    int onFocus() override {
        return this->weight_ / 2;
    }
};

void Object::fire(int value) {
    Some * some = dynamic_cast<Some *>(this);
    if (some) {
        some->setHeight(value);
        cout << "Height " << value;
    } else {
        Thing * thing = dynamic_cast<Thing *>(this);
        if (thing) {
            thing->setWeight(value);
            cout << "Weight " << value;
        }
    }
    int focus = onFocus();
    cout << " with Focus Degree " << focus << endl;
}

int main() {
    int n;
    int mode, value;

    if(sizeof(Object) > 8)
        return -1;

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> mode >> value;
        if (mode > 5) {
            Some some;
            if (mode % 2) {
                some.fire(value);
            } 
        } else {
            Thing thing;
            if (mode % 2) {
                thing.fire(value);
            }
        }
    }
    return 0;
}

