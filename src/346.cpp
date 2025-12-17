#include <iostream>
using namespace std;
// ____qcodep____

class Complex{
private:
    double real, imag;

public:
    Complex(double re = 0.0, double im = 0.0) : real(re), imag(im){};
    ~Complex(){}
    void show(){
        if(this->imag == 0 && this->real != 0){
            cout << real << endl;
            return;
        }
        if(this->real == 0 && this->imag != 0){
            cout << imag << "i" << endl;
            return;
        }
        if(this->real == 0 && this -> imag == 0){
            cout << 0 << endl;
            return;
        }
        if (this->imag > 0)
            cout << this->real << "+" << this->imag << "i" << endl;
        else
            cout << this->real << this->imag << "i" << endl;
        return;
    }

    void add(Complex&other){
        this->real = this->real + other.real;
        this->imag = this->imag + other.imag;
    }
    void sub(Complex&other){
        this->real = this->real - other.real;
        this->imag = this->imag - other.imag;
    }
};

int main()
{
	double re, im;
	cin >> re >> im;
	Complex c1(re, im);		// 用re, im初始化c1
	cin >> re;
	Complex c2 = re;     		// 用实数re初始化c2

	c1.show();
	c2.show();
	c1.add(c2);         // 将C1与c2相加，结果保存在c1中
	c1.show();          // 将c1输出
	c2.sub(c1);			// c2-c1，结果保存在c2中 
	c2.show();			// 输出c2 
	
    return 0;
}
