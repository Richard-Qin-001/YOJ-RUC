#include <iostream>
#include <math.h>

using namespace std;

class Point
{
public:
    Point(double x, double y);
    Point(const Point &p);
    double getX() const;
    double getY() const;
protected:
    double _x, _y;
};

Point::Point(double x, double y):_x(x), _y(y){
}

Point::Point(const Point &p):_x(p._x), _y(p._y){
}

double Point::getX() const
{
    return this->_x;
}

double Point::getY() const
{
    return this->_y;
}

class Rectangle{
public:
    Rectangle(const Point & lb, const Point & rt);
    // ____qcodep____
    Rectangle operator+(const Rectangle &other) const;
    Point getLB() const { return _lb; }
    Point getRT() const { return _rt; }

private:
    Point _lb, _rt;
};
// ____qcodep____
Rectangle::Rectangle(const Point &lb, const Point &rt) : _lb(lb), _rt(rt) {}

Rectangle Rectangle::operator+(const Rectangle &other) const {
    double minX = (this->_lb.getX() < other._lb.getX()) ? this->_lb.getX() : other._lb.getX();
    double minY = (this->_lb.getY() < other._lb.getY()) ? this->_lb.getY() : other._lb.getY();

    double maxX = (this->_rt.getX() > other._rt.getX()) ? this->_rt.getX() : other._rt.getX();
    double maxY = (this->_rt.getY() > other._rt.getY()) ? this->_rt.getY() : other._rt.getY();

    return Rectangle(Point(minX, minY), Point(maxX, maxY));
}

void printRectangle(Rectangle rec){
    cout<<rec.getLB().getX()<<" "<<rec.getLB().getY()<<endl;
    cout<<rec.getRT().getX()<<" "<<rec.getRT().getY()<<endl;
}

int main()
{
    double x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    Rectangle r1(Point(x1,y1), Point(x2,y2));
    cin>>x1>>y1>>x2>>y2;
    Rectangle r2(Point(x1,y1), Point(x2,y2));
    Rectangle r3 = r1 + r2;
    printRectangle(r3);
    return 0;
}
