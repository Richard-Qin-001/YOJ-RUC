#include <iostream>
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;
const float PI = 3.141592653;

class Circle
{
public:
    double getArea() const;
    double getRadius(){return r;}
    void setRadius(int pr){r = pr;}
    ~Circle();
private:
    int r;
protected:
    const float COURSE_PI;
public:
    // ____qcodep____

    static int c_count;
    Circle(int radius = 0) : r(radius), COURSE_PI(PI) {
        c_count++;
    }
};

// ____qcodep____

int Circle::c_count = 0;

Circle::~Circle()
{
    c_count--;
}

double Circle::getArea() const{
    return r * r * COURSE_PI;
}

class RectCircle : public Circle
{
public:
    RectCircle(int r=0);
    RectCircle(const RectCircle &rc);
    ~RectCircle(){
        rc_count --;
    }
    double getRectArea() const;
public:
    static int rc_count;
};

// ____qcodep____

int RectCircle::rc_count = 0;

RectCircle::RectCircle(int r) : Circle(r){
    rc_count++;
}

RectCircle::RectCircle(const RectCircle &rc):Circle(rc)
{
    rc_count ++;
}

double RectCircle::getRectArea() const
{
        double d = sqrt(2.0 * (this->Circle::getArea()/this->COURSE_PI));
        double innerArea= d*d;
        d = 2.0 * sqrt(this->Circle::getArea()/this->COURSE_PI);
        double outerArea = d*d;
        return innerArea + outerArea;
}

int main()
{
    int circleNum, circleR, rectCircleNum, rectCircleR;
    cin>>circleNum>>circleR>>rectCircleNum>>rectCircleR;

    double rectALLArea =0.0;
    RectCircle *rcArray = new RectCircle[rectCircleNum];
    for(int i=0;i<rectCircleNum; i++){
        rcArray[i].setRadius(rectCircleR);
        rectALLArea = rectALLArea +rcArray[i].getRectArea();
    }
    // ____qcodep____
    double circleAllArea = 0.0;
    Circle *cArray = new Circle[circleNum];
    for(int i = 0; i < circleNum; ++i){
        cArray[i].setRadius(circleR);
        circleAllArea = circleAllArea + cArray[i].getArea();
    }
    for(int i = 0; i < rectCircleNum; ++i){
        circleAllArea = circleAllArea + rcArray[i].getArea();
    }
    cout<<setiosflags(ios::fixed)<<Circle::c_count<<setprecision(1)<<" "<<circleAllArea<<endl;
    cout<<setiosflags(ios::fixed)<<RectCircle::rc_count<<setprecision(1)<<" "<<rectALLArea<<endl;


    delete [] rcArray;
    delete [] cArray;

    return 0;
}