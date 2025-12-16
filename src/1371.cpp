#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Polynomial
{
private:
   vector<double> coefficients; // 系数，从低次项到高次项存储
public:
   Polynomial(const vector<double> &coeffs) : coefficients(coeffs) {}

   // 成员函数：重载加法运算符
//    ____qcodep____
    Polynomial operator+(const Polynomial&other) const {
        int n = coefficients.size();
        int m = other.coefficients.size();
        int maxLen = max(n, m);
        vector<double> res(maxLen);
        for (int i = 0; i < maxLen; ++i)
        {
            double a = (i < n) ? coefficients[i] : 0;
            double b = (i < m) ? other.coefficients[i] : 0;
            res[i] = a + b;
        }
        return Polynomial(res);
    }

       // 友元函数：重载减法运算符
    //    ____qcodep____

    friend Polynomial operator-(const Polynomial&a, const Polynomial&b);

           // 求值函数
        //    ____qcodep____
    double evaluate(double x){
        double val = 0.0;
        for(int i = coefficients.size() - 1; i >= 0; --i){
            val = val * x + coefficients[i];
        }
        return val;
    }

    // 声明友元输出运算符
    //    ____qcodep____

    friend ostream &operator<<(ostream &os, const Polynomial &p);
};

// 实现友元输出运算符
// ____qcodep____
ostream &operator<<(ostream &os, const Polynomial &p)
{
    bool first = true;
    // 从最高次项向低次项遍历
    for (int i = (int)p.coefficients.size() - 1; i >= 0; --i)
    {
        double val = p.coefficients[i];

        if (val == 0 && i != 0)continue;
        if (!first && val > 0)os << "+";
        if (val < 0){
            os << "-";
            val = -val;
        }
        else if (val == 0 && !first){
            os << "+";
        }
        if (val != 1 || i == 0)os << val;
        if (i > 0){
            os << "x";
            if (i > 1)os << "^" << i;
        }
        first = false;
    }
    if (first)os << "0";
    return os;
}

    // 实现友元减法运算符
    // ____qcodep____
Polynomial operator-(const Polynomial &a, const Polynomial &b)
{
    int n = a.coefficients.size();
    int m = b.coefficients.size();
    int maxLen = max(n, m);
    vector<double> res(maxLen);
    for (int i = 0; i < maxLen; ++i){
        double valA = (i < n) ? a.coefficients[i] : 0;
        double valB = (i < m) ? b.coefficients[i] : 0;
        res[i] = valA - valB;
    }
    return Polynomial(res);
}
    // 函数指针类型

typedef Polynomial (*PolyOperation)(const Polynomial &, const Polynomial &);

int main()
{
   int n, m;
   cin >> n;
   vector<double> coeffs1(n + 1);
   for (double &c : coeffs1)
      cin >> c;

   cin >> m;
   vector<double> coeffs2(m + 1);
   for (double &c : coeffs2)
      cin >> c;

   Polynomial p1(coeffs1), p2(coeffs2);

   // 测试加法
   Polynomial sum = p1 + p2;
   cout << "Sum: " << sum << endl;

   // 测试减法
   Polynomial diff = p1 - p2;
   cout << "Difference: " << diff << endl;

   // 测试求值
   double x;
   cin >> x;
   cout << "P1(" << x << ") = " << p1.evaluate(x) << endl;
   cout << "P2(" << x << ") = " << p2.evaluate(x) << endl;

   // 测试函数指针
   PolyOperation op = [](const Polynomial &a, const Polynomial &b)
   {
      return a + b;
   };
   cout << "Function pointer (addition): " << op(p1, p2) << endl;

   return 0;
}
