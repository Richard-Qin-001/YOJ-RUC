#include <iostream>
#include <iomanip>
using namespace std;
// ____qcodep____
#include <cmath>
class Complex
{
private:
    double real;
    double imag;
public:
    Complex(double r = 0.0, double i = 0.0);
    ~Complex();
    double getReal() const { return real; }
    double getImag() const { return imag; }
    Complex operator+(const Complex& other) const;
    friend Complex operator+(double d, const Complex& c);
    friend Complex operator+(const Complex& c, double d);
    friend ostream& operator<<(std::ostream& os, const Complex& c);
};

Complex::Complex(double r, double i): real(r), imag(i) {}

Complex::~Complex()
{
}

Complex Complex::operator+(const Complex& other) const {
    double newReal = this->real + other.real;
    double newImag = this->imag + other.imag;
    return Complex(newReal, newImag);
}
Complex operator+(double d, const Complex& c){
    return Complex(d+ c.real, c.imag);
}
Complex operator+(const Complex& c, double d){
    return Complex(d+ c.real, c.imag);
}

ostream& operator<<(ostream&os, const Complex& c){
    os << "(";
    os << fixed << setprecision(2);
    os << c.real;
    if (c.imag >= 0) os << "+";
    else os << "-";
    os << abs(c.imag);
    os << "i)";
    os << defaultfloat;
    os << endl;
    return os;
}

int main()
{
    //测试复数加复数
    double real,imag;
    cin>>real>>imag;
    Complex c1(real,imag);
    cin>>real>>imag;
    Complex c2(real,imag);
    Complex c3=c1+c2;
    cout<<"c1+c2=";
    cout<<c3;
 
    //测试复数加实数
    double d;
    cin>>real>>imag;
    cin>>d;
    c3=Complex(real,imag)+d;
    cout<<"c1+d=";
    cout<<c3;
 
    //测试实数加复数
    cin>>d;
    cin>>real>>imag;
    c1=Complex(real,imag);
    c3=d+c1;
    cout<<"d+c1=";
    cout<<c3;
 
    return 0;
}