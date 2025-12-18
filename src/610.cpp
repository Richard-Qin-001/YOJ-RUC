#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
using std::cin;

class Object {
public:
    Object() = default;
    Object(const char* _name);
private:
    int id;
    char name[20];

// ____qcodep____

    friend std::ostream& operator<<(std::ostream&out, const Object&obj){
        out << obj.id << " " << obj.name;
        return out;
    }
    static int curr_max_id;
public:
    Object(const Object &other);
    Object& operator=(const Object&other);

    int getId() const {
        return id;
    }
    const char *getName() const {
        return name;
    }
};

// ____qcodep____
int Object::curr_max_id = 0;
Object::Object(const char*_name){
    id = ++curr_max_id;
    strcpy(name, _name);
}

Object::Object(const Object&other){
    id = ++curr_max_id;
    strcpy(name, other.name);
}

Object& Object::operator=(const Object&other){
    if (this != &other){
        this->id = other.id;
        strcpy(this->name, other.name);
    }
    return *this;
}

int main() {
    int n;
    char name[20];
    int mode;
    Object objects[10];
    cin >> n;
    //objects = new Object[n];
    for (int i = 0; i < n; i++) {
        cin >> name >> mode;
        //cout << name << "  " << mode << endl;
        if (mode == 1)  {
        	if (!i) {
        		objects[0] = Object(name);
        	} else {
        		Object obj = objects[i-1];
        		objects[i] = obj; // 本行代码不会使objects[i]的id相比obj而言增加1，实现代码时无需考虑
        	}
        } else {
        	objects[i] = Object(name);
        }
    }
    for (int i = 0; i < n; i++) {
    	Object & obj = objects[i];
    	cout << obj << endl;
    }
    return 0;
}

