#include <iostream>
#include <iomanip>
using namespace std;
// ____qcodep____

class Shape
{
public:
    virtual double area() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape{
private:
    float radius;

public:
    Circle(float r) : radius(r) {}
    double area() const { return 3.14159265358979 * radius * radius; }
};

class Square : public Shape
{
private:
    float side;

public:
    Square(float s) : side(s) {}
    double area() const { return (double)side * side; }
};

class Rectangle : public Shape
{
private:
    float width, height;

public:
    Rectangle(float w, float h) : width(w), height(h) {}
    double area() const { return (double)width * height; }
};

class Trapezoid : public Shape
{
private:
    float top, bottom, height;

public:
    Trapezoid(float t, float b, float h) : top(t), bottom(b), height(h) {}
    double area() const { return ((double)top + bottom) * height / 2.0; }
};

class Triangle : public Shape
{
private:
    float base, height;
public:
    Triangle(float b, float h) : base(b), height(h) {}
    double area() const { return (double)base * height / 2.0; }
};

int main()
{ 
    float r,a,b,w1,w2,w,h; 
    cout<<fixed<<setprecision(2);
    cin>>r;
    Circle circle(r); 
    cin>>a;
    Square square(a);
    cin>>a>>b;
    Rectangle rectangle(a,b);
    cin>>w1>>w2>>h;
    Trapezoid trapezoid(w1,w1,h);
    cin>>w>>h;
    Triangle triangle(w,h);
    Shape *pt[5]= {&circle,&square,&rectangle,&trapezoid,&triangle};
    double areas=0.0;
    for(int i=0; i<5; i++)
         areas=areas+pt[i]->area();
    cout<<"total of all areas="<<areas<<endl;
    return 0;
}
 