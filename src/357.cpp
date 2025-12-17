#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

class Circle
{ 
public:
    Circle(int r);
   //此处可补充代码
//    ____qcodep____
    int getR()const{
        return r;
    }

private:
    int r;
protected:
    const float COURSE_PI= 3.141592653;
};
Circle::Circle(int r):r(r){
}

class RectCircle : public Circle
{
public:
    RectCircle(int r=0, int t=0);
    double getArea() const;
private:
    int inner=0;
};
RectCircle::RectCircle(int r,int t):Circle(r),inner(t){}
double RectCircle::getArea() const {
    switch (inner)
    {
    case 0:
        return COURSE_PI * getR() * getR()+ 2.0 * getR() * getR(); 
        break;
    case 1:
        return COURSE_PI * getR() * getR() + 4.0 * getR() * getR();
        break;
    case 2:
        return COURSE_PI * getR() * getR();
        break;
    }
}

//此处可补充代码
// ____qcodep____

int main(int argc, char *argv[])
{
    int r, type;
    cin>>r>>type;
    RectCircle A(r,type);
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<A.getArea();
    return 0;
}