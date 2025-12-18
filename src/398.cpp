#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

// ____qcodep____
class CShape{
public:
    virtual double Area() = 0;
    virtual void PrintInfo() = 0;
    virtual ~CShape() {}
};
class CRectangle : public CShape{
    double w, h;
public:
    CRectangle(double _w, double _h) : w(_w), h(_h) {}
    double Area() { return w * h; }
    void PrintInfo() { cout << "Rectangle:" << Area() << endl; }
};

class CCircle : public CShape
{
    double r;

public:
    CCircle(double _r) : r(_r) {}
    double Area() { return 3.14 * r * r; }
    void PrintInfo() { cout << "Circle:" << Area() << endl; }
};

class CTriangle : public CShape{
    double a, b, c;
public:
    CTriangle(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
    double Area(){
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    void PrintInfo() { cout << "Triangle:" << Area() << endl; }
};

int MyCompare(const void * s1, const void * s2) {
  double a1, a2;
  CShape ** p1;
  CShape ** p2;
  p1 = (CShape **) s1;
  p2 = (CShape **) s2;
  a1 = (*p1)->Area(); 
  a2 = (*p2)->Area();
  if( a1 < a2 )
    return -1;
  else if ( a2 < a1 )
    return 1;
  else
    return 0;
}

int main() {
  int n;
  CShape ** pShapes;

  cin >> n;
  pShapes = new CShape*[n];
  for(int i=0; i<n; i++ ) {
    char c;
    cin >> c;
    switch(c) {
    case 'R':
        // ____qcodep____
        double w, h;
        cin >> w >> h;
        pShapes[i] = new CRectangle(w, h);
        break;
    case 'C':
        // ____qcodep____
        double r;
        cin >> r;
        pShapes[i] = new CCircle(r);
        break;
    case 'T':
        // ____qcodep____
        double a, b, c;
        cin >> a >> b >> c;
        pShapes[i] = new CTriangle(a, b, c);
        break;
    }
  }

  qsort(pShapes, n, sizeof(CShape*), MyCompare);
  for(int i=0; i<n; i++)
    pShapes[i]->PrintInfo();

  for(int i=0; i<n; i++)
      delete pShapes[i];
  delete [] pShapes;

  return 0;
}