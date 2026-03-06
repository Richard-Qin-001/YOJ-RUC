/*
复数的乘积：

输入样例：
2
3 6 4 5
5 8 3 2

第一行表示初始变量n=2。接下来有n行，每一行有四个int类型的参数，分别为复数1的实部与虚部、复数2的实部与虚部。

对应的输出为：
12 30
15 16

共有n行输出，每一行输出为两个数，为对应输入行的两个复数的实部的乘积与虚部的乘积。
*/

#include <iostream>
using namespace std;

class Complex2;
class Complex1
{
private:
    int real, imag; // real:实部 imag:虚部
public:
    Complex1(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }
    pair<int, int> getter()
    {
        return {real, imag};
    }
    Complex1 operator<<(Complex2 &c2);
};
class Complex2
{
private:
    int real, imag; // real:实部 imag:虚部
public:
    Complex2(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }

    // ____qcodep____
    pair<int, int> getter()
    {
        return {real, imag};
    }
};

// ____qcodep____
Complex1 Complex1::operator<<(Complex2 &c2){
    return {this->getter().first * c2.getter().first, this->getter().second * c2.getter().second};
}


int main()
{
    int n, x, y, l, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> l >> m;
        Complex1 a(x, y);
        Complex2 b(l, m);
        cout << (a << b).getter().first << " " << (a << b).getter().second << endl;
    }
}