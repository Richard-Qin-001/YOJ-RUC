#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class StringUtils
{
public:
    double str2Double(const string & s);
        //字符串转double，以下类似
    string double2Str(double d);
    int str2Int(const string & s);
    string int2Str(int i);
};

string StringUtils::double2Str(double d){
    string res = "";
    stringstream ss;
    ss << d;
    ss >> res;
    return res;
}

string StringUtils::int2Str(int i){
    string res = "";
    stringstream ss;
    ss << i;
    ss >> res;
    return res;
}

double StringUtils::str2Double(const string &s){
    stringstream ss;
    ss << s;
    double d = 0;
    ss >> d;
    return d;
}


int StringUtils::str2Int(const string &s){
    stringstream ss;
    ss << s;
    int i = 0;
    ss >> i;
    return i;
}

//以下部分定义并实现IntNumber类
// ____qcodep____ 
class IntNumber
{
private:
    long long number;
    StringUtils su;

public:
    IntNumber(string num);
    ~IntNumber();
    string getVal();
    void add(IntNumber&other);
    void setVal(string num);
    void subtract(IntNumber&other);
};

IntNumber::IntNumber(string num)
{
    number = su.str2Int(num);
}

IntNumber::~IntNumber()
{
}
string IntNumber::getVal(){
    return su.int2Str(number);
}
void IntNumber::add(IntNumber&other){
    this->number = other.number + this->number;
}
void IntNumber::setVal(string num){
    this->number = su.str2Int(num);
}
void IntNumber::subtract(IntNumber&other){
    this->number -= other.number;
}


int main()
{
    //读入两个整数；
    //输出两行；第一行是两个整数的相加的结果
    //第二行是第一个整数减去第二个整数的结果

    string s1, s2;
    cin>>s1;
    cin>>s2;

    IntNumber n1(s1);
    IntNumber n2(s2);
    n1.add(n2);
    cout<<n1.getVal()<<endl;

    n1.setVal(s1);
    n1.subtract(n2);
        //n1 减去 n2，结果存储于 n1
    cout<<n1.getVal()<<endl;

    return 0;
}