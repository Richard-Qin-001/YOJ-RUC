/*
类Shape,及其派生类Rectangl和Circle类的设计与完善
派生出类Rectangle和Circle都有计算对象面积的函数getArea(),计算对象周长的函数getPerim（）.
*/
#include <iostream>
using namespace std;

class Shape
{
public:
    Shape() {  }
    //此处填空，补充必要的函数
    // ____qcodep____
    virtual double getArea() = 0;
    virtual double getPerim() = 0; 

};
class Rectangle :public Shape
{
public:
    Rectangle(float i = 0, float j = 0) :m_i(i), m_j(j)
    {
    }
    //此处填空，补充完善补充必要的成员函数
    // ____qcodep____
    double getArea() override {
        return m_i * m_j;
    }
    double getPerim() override {
        return (m_i + m_j) * 2;
    }
    
    
private:
    float m_i;                         //矩形的长
    float m_j;                        //矩形的宽
};
class Circle :public Shape
{
public:
    Circle(float i = 0) :m_k(i)
    {
    }
    //此处填空，补充完善补充必要的成员函数
    // ____qcodep____   
    double getArea() override {
        return 3.14 * m_k * m_k;
    } 
    double getPerim() override {
        return 3.14 * m_k * 2;
    }
private:
    float m_k;                         //半径
};

//用于显示面积与周长的show()函数
void show(Shape *shape) {
    cout << shape->getArea() << endl;
    cout << (*shape).getPerim() << endl;
}

int main()
{
    Shape *pRect, *pCircle;
    double length, width, rr;
    cin >> length >> width;
    cin >> rr;
    pRect = new Rectangle(length, width);
    pCircle = new Circle(rr);
    show(pRect);        //打印出图形的面积和周长 
    show(pCircle);        //打印出图形的面积和周长
    return 0; 
}
