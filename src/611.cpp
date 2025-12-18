#include <iostream>
#include <string.h>
#include <memory.h>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

class Object {
public:
    Object() = default;
    Object(const Object & obj) {
        cout << "Should not enter this function" << endl;
    }

protected:
    mutable char name[20];
    
public:
    const char *getName() const {
        strcat(name+strlen(name), "-in Object");
        return name;
    }
    const char *getName() {
        cout << "Should not enter this function" << endl;
        return "";
    }
};

// ____qcodep____
class Some : public Object {
public:
    Some(const char* _name);
    Some(const Some&other);
    const char *getName() const {
        return name;
    }
};

Some::Some(const char* _name){
    strcpy(name, _name);
}
Some::Some(const Some&other){
    if(this != &other){
        strcpy(this->name, other.name);
    }
}

int main() {
    int n;
    char name[20];
    int mode;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name >> mode;
        const Some some(name);
        memset(name, 0, 20);
        
        // ____qcodep____

        if(mode == 0){
            cout << some.getName() << endl;
        }
        if(mode == 1){
            const Object& obj_ref = some;
            cout << obj_ref.getName() << endl;
        }
    }
    
    return 0;
}

