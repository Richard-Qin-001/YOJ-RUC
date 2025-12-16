#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Complex
{
private:
   double real;
   double imag;

public:
   Complex(double r = 0, double i = 0) : real(r), imag(i) {}

   // 重载加法运算符（成员函数形式）
//    ____qcodep____
    Complex operator+(const Complex&other) const {
        Complex c;
        c.real = this->real + other.real;
        c.imag = this->imag + other.imag;
        return c;
    }

       // 重载减法运算符（友元函数形式）
    //    ____qcodep____

    friend Complex operator-(const Complex &a, const Complex &b);

    // 获取模长
    double magnitude() const
   {
      return sqrt(real * real + imag * imag);
   }

   // 声明友元输出运算符
//    ____qcodep____
   friend ostream& operator<<(ostream&os, const Complex&c);
};

// 实现友元输出运算符
// ____qcodep____

ostream& operator<<(ostream&os, const Complex&c){
    os << "(" << c.real << ","<< c.imag << ")";
    return os;
}

    // 实现友元减法运算符
    // ____qcodep____
Complex operator-(const Complex &a, const Complex &b)
{
    return Complex(a.real - b.real, a.imag - b.imag);
}

    // 比较复数模长的函数对象
class CompareComplex
{
public:
   bool operator()(const Complex &a, const Complex &b) const
   {
    //   ____qcodep____
    return a.magnitude() > b.magnitude();
   }
};

// 复数运算的函数指针类型
typedef Complex (*ComplexOperation)(const Complex &, const Complex &);

int main()
{
   double r1, i1, r2, i2;
   while (cin >> r1 >> i1 >> r2 >> i2)
   {
      Complex c1(r1, i1), c2(r2, i2);

      // 测试加法运算符
      Complex c3 = c1 + c2;
      cout << "Addition: " << c3 << endl;

      // 测试减法运算符
      Complex c4 = c1 - c2;
      cout << "Subtraction: " << c4 << endl;

      // 测试比较函数对象
      CompareComplex comp;
      cout << "Comparison: " << (comp(c1, c2) ? "c1 > c2" : "c1 <= c2") << endl;

      // 使用函数指针动态调用运算
      ComplexOperation op = [](const Complex &a, const Complex &b)
      {
         return a + b;
      };
      cout << "Function pointer: " << op(c1, c2) << endl;
   }
   return 0;
}