#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

//下面需要补充多个类的声明及实现代码
// ____qcodep____
const double epsilon = 1e-6;

class Point{
public:
    double x, y;
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    double dist(const Point &p) const{
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }
};

class Quadrilateral
{
public:
    Quadrilateral(vector<Point> vertices) : _vertices(vertices) {}
    double getArea();
    double getPerimeter();
    virtual bool verify();

protected:
    vector<Point> _vertices;
};

double cross_product(Point a, Point b, Point c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool Quadrilateral::verify()
{
    if (_vertices.size() < 4)
        return false;
    double cp1 = cross_product(_vertices[0], _vertices[1], _vertices[2]);
    double cp2 = cross_product(_vertices[1], _vertices[2], _vertices[3]);
    double cp3 = cross_product(_vertices[2], _vertices[3], _vertices[0]);
    double cp4 = cross_product(_vertices[3], _vertices[0], _vertices[1]);

    if ((cp1 > epsilon && cp2 > epsilon && cp3 > epsilon && cp4 > epsilon) ||
        (cp1 < -epsilon && cp2 < -epsilon && cp3 < -epsilon && cp4 < -epsilon))
    {
        return true;
    }
    return false;
}

double Quadrilateral::getArea()
{
    if (!verify())
        return 0.0;
    double area = 0;
    for (int i = 0; i < 4; i++)
    {
        area += (_vertices[i].x * _vertices[(i + 1) % 4].y - _vertices[(i + 1) % 4].x * _vertices[i].y);
    }
    return abs(area) / 2.0;
}

double Quadrilateral::getPerimeter()
{
    if (!verify())
        return 0.0;
    double p = 0;
    for (int i = 0; i < 4; i++)
    {
        p += _vertices[i].dist(_vertices[(i + 1) % 4]);
    }
    return p;
}

class Parallelogram : public Quadrilateral
{
public:
    Parallelogram(vector<Point> v) : Quadrilateral(v) {}
    bool verify() override
    {
        if (!Quadrilateral::verify())
            return false;
        double d1 = _vertices[0].dist(_vertices[1]);
        double d2 = _vertices[1].dist(_vertices[2]);
        double d3 = _vertices[2].dist(_vertices[3]);
        double d4 = _vertices[3].dist(_vertices[0]);
        return (abs(d1 - d3) < epsilon && abs(d2 - d4) < epsilon);
    }
};

class Rectangle : public Parallelogram
{
public:
    Rectangle(vector<Point> v) : Parallelogram(v) {}
    bool verify() override
    {
        if (!Parallelogram::verify())
            return false;
        double diag1 = _vertices[0].dist(_vertices[2]);
        double diag2 = _vertices[1].dist(_vertices[3]);
        return (abs(diag1 - diag2) < epsilon);
    }
};

//填空结束
 

int main()
{
    vector<Point> vertices;
    for (int i=0;i<4;i++){
        double x,y;
        cin>>x>>y;
        Point p(x,y);
        vertices.push_back(p);
    }

    Quadrilateral q(vertices);
    Parallelogram pa(vertices);
    Rectangle r(vertices);

    cout<<fixed<<setprecision(2);

    cout<<(q.verify()?1:0)<<endl;
    cout<<q.getArea()<<endl;
    cout<<q.getPerimeter()<<endl;

    cout<<(pa.verify()?1:0)<<endl;
    cout<<pa.getArea()<<endl;
    cout<<pa.getPerimeter()<<endl;

    cout<<(r.verify()?1:0)<<endl;
    cout<<r.getArea()<<endl;
    cout<<r.getPerimeter()<<endl;

    return 0;
}