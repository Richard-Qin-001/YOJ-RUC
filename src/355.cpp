#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
class MyStr{
public:
    MyStr(const char * s);
    ~MyStr();    
    //将输入的字符串加到当前字符串末尾
    void myStrcat(const MyStr & str1);
    char * getStr() const;

    //此处可补充代码
    // ____qcodep____
    MyStr(const MyStr &other);

private:
    int size;
    char * data;
};

MyStr::~MyStr(){
    delete [] data;
}

char * MyStr::getStr() const{
    return this->data;
}

//此处可补充代码
// ____qcodep____
MyStr::MyStr(const char *s){
    this->size = strlen(s);
    data = new char[size + 1];
    strcpy(data, s);
}

MyStr::MyStr::MyStr(const MyStr&other){
    size = other.size;
    data = new char[size + 1];
    strcpy(data, other.data);
}

void MyStr::myStrcat(const MyStr & str1){
    int newSize = size + str1.size;
    char *newData = new char[newSize + 1];
    strcpy(newData, data);
    strcat(newData, str1.data);

    delete [] data;
    data = newData;
    size = newSize;
}

int main(){
    char tempStr[20];
    cin>>tempStr;
    MyStr * s0 = new MyStr(tempStr);
    MyStr * s1 = new MyStr(*s0);
    s1->myStrcat(*s0);
    cout<<s1->getStr()<<endl;
    s1->~MyStr();
    cout<<s0->getStr()<<endl;
    s0->~MyStr();
    return 0;
}