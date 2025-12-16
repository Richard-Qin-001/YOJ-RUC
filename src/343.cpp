#include <iostream>
#include <math.h>
#include<iomanip>

using namespace std;

class Rectangle{

public:
//在下面的空格声明 Rectangle 类的成员函数
    // ____qcodep____

    Rectangle(double x1, double y1, double x2, double y2);
    ~Rectangle();
    double getC();
    double getS();

private:
    //左下角坐标
    double _x1;
    double _y1;

    //右上角坐标
    double _x2;
    double _y2;

    //宽度和高度
    double _width;
    double _height;
};

//在下面的空格实现 Rectangle 类的成员函数
// ____qcodep____

Rectangle::Rectangle::Rectangle(double x1, double y1, double x2, double y2) : _x1(x1), _y1(y1), _x2(x2), _y2(y2)
{
    _width = abs(x2 - x1);
    _height = abs(y2 - y1);
}
Rectangle::Rectangle::~Rectangle(){}
double Rectangle::getC(){
    return (_width + _height) * 2;
}
double Rectangle::getS(){
    return (_width * _height);
}

int main(){

    double x1, x2, y1, y2;
    cin >>x1>>y1>>x2>>y2;
    Rectangle r1(x1,y1,x2,y2);

    Rectangle r2 = r1;

//在下面的空格按题目要求输出结果

// ____qcodep____

    cout << fixed << setprecision(2);
    cout << r1.getC() << endl;
    cout << r2.getS() << endl;
    cout << r1.getC() + r2.getC() << endl;
    cout << r1.getS() + r2.getS() << endl;

    return 0;
}
