#include <iostream>
#include<string> 
#include<stdio.h>
#include<cmath>

using namespace std;

typedef void (*CalFunc)();


class DCell;
class NCell
{
public:
    NCell();
    NCell(long long value);

  // 填空1  定义NCell的操作函数 
    // ____qcodep____
    NCell(const DCell &other);

    long long getValue() const;
    void setValue(long long value);
    NCell operator+(const NCell &other);
    NCell operator-(const NCell &other);
    NCell operator*(const NCell &other);
    NCell operator/(const NCell &other);
    NCell operator+=(const NCell &other);
    NCell operator+(const DCell &other);
    NCell operator-(const DCell &other);
    NCell operator*(const DCell &other);
    NCell operator/(const DCell &other);
    NCell operator+=(const DCell &other);
    // 填空1结束

private:
    long long llvalue;
};

NCell::NCell()
{   
    llvalue = 0;
}

NCell::NCell(long long value)
{
    setValue(value);
}

long long NCell::getValue() const
{
    return llvalue;
}

void NCell::setValue(long long value)
{
    llvalue = value;
}


class DCell
{
public:
    DCell();
    DCell(double value);
    
    // 填空2 开始 定义DCell的操作函数 
    // ____qcodep____
    DCell(const NCell &other);

    double getValue() const;
    void setValue(double value);
    DCell operator+(const DCell &other);
    DCell operator-(const DCell &other);
    DCell operator*(const DCell &other);
    DCell operator/(const DCell &other);
    DCell operator+=(const DCell &other);
    DCell operator+(const NCell &other);
    DCell operator-(const NCell &other);
    DCell operator*(const NCell &other);
    DCell operator/(const NCell &other);
    DCell operator+=(const NCell &other);
    // 填空2 结束

private:
    double dvalue;
};

DCell::DCell()
{
    dvalue = 0.0;
}

DCell::DCell(double dvalue)
{
    setValue(dvalue);
}

double DCell::getValue() const
{
    return dvalue;
}

void DCell::setValue(double value)
{
    dvalue = value;
}


//填空3开始  实现NCEll和DCEll的操作函数 
// ____qcodep____

NCell NCell::operator+(const NCell &other)
{
    return NCell(llvalue + other.llvalue);
}

NCell NCell::operator-(const NCell &other)
{
    return NCell(llvalue - other.llvalue);
}

NCell NCell::operator*(const NCell &other)
{
    return NCell(llvalue * other.llvalue);
}

NCell NCell::operator/(const NCell &other)
{
    return NCell(llvalue / other.llvalue);
}

NCell NCell::operator+=(const NCell &other)
{
    llvalue += other.llvalue;
    return *this;
}

NCell NCell::operator+(const DCell &other)
{
    return NCell((long long)(llvalue + other.getValue()));
}

NCell NCell::operator-(const DCell &other)
{
    return NCell((long long)(llvalue - other.getValue()));
}

NCell NCell::operator*(const DCell &other)
{
    return NCell((long long)(llvalue * other.getValue()));
}

NCell NCell::operator/(const DCell &other)
{
    return NCell((long long)(llvalue / other.getValue()));
}

NCell NCell::operator+=(const DCell &other)
{
    llvalue = (long long)(llvalue + other.getValue());
    return *this;
}

NCell operator-(const NCell &obj)
{
    return NCell(-obj.getValue());
}

DCell DCell::operator+(const DCell &other)
{
    return DCell(dvalue + other.dvalue);
}

DCell DCell::operator-(const DCell &other)
{
    return DCell(dvalue - other.dvalue);
}

DCell DCell::operator*(const DCell &other)
{
    return DCell(dvalue * other.dvalue);
}

DCell DCell::operator/(const DCell &other)
{
    return DCell(dvalue / other.dvalue);
}

DCell DCell::operator+=(const DCell &other)
{
    dvalue += other.dvalue;
    return *this;
}

DCell DCell::operator+(const NCell &other)
{
    return DCell(dvalue + other.getValue());
}

DCell DCell::operator-(const NCell &other)
{
    return DCell(dvalue - other.getValue());
}

DCell DCell::operator*(const NCell &other)
{
    return DCell(dvalue * other.getValue());
}

DCell DCell::operator/(const NCell &other)
{
    return DCell(dvalue / other.getValue());
}

DCell DCell::operator+=(const NCell &other)
{
    dvalue += other.getValue();
    return *this;
}

DCell operator-(const DCell &obj)
{
    return DCell(-obj.getValue());
}

NCell::NCell(const DCell &other)
{
    llvalue = static_cast<long long> (other.getValue());
}

DCell::DCell(const NCell &other)
{
    dvalue = static_cast<double> (other.getValue());
}

// 填空3结束 

class Calculator
{
public:
    static CalFunc Func[25];

    static void init();//0
    static void fsum();//1
    static void nsum();

    static void twollnPlus();
    static void twollnMinus();
    static void twollnMulti();
    static void twollnDivis();
    static void twollnPlusEq();

    static void twodblPlus();
    static void twodblMinus();
    static void twodblMulti();
    static void twodblDivis();
    static void twodblPlusEq();

    static void llnPlusDbl();
    static void llnMinusDbl();
    static void llnMultiDbl();
    static void llnDivisDbl();

    static void dblPlusLln();
    static void dblMinusLln();
    static void dblMultiLln();
    static void dblDivisLln();

    static void llnAssignedToDbl();
    static void dblAssignedToLln();

    static void nelln();
    static void nedbl();//24

    static int DecodeFuncIdx(unsigned code);


};

CalFunc Calculator::Func[25];
void Calculator::init()
{
    Func[0] = Calculator::init;
    Func[1] = Calculator::fsum;
    Func[2] = Calculator::nsum;
    Func[3] = Calculator::twollnPlus;
    Func[4] = Calculator::twollnMinus;
    Func[5] = Calculator::twollnMulti;
    Func[6] = Calculator::twollnDivis;
    Func[7] = Calculator::twollnPlusEq;
    Func[8] = Calculator::twodblPlus;
    Func[9] = Calculator::twodblMinus;
    Func[10] = Calculator::twodblMulti;
    Func[11] = Calculator::twodblDivis;
    Func[12] = Calculator::twodblPlusEq;
    Func[13] = Calculator::llnPlusDbl;
    Func[14] = Calculator::llnMinusDbl;
    Func[15] = Calculator::llnMultiDbl;
    Func[16] = Calculator::llnDivisDbl;
    Func[17] = Calculator::dblPlusLln;
    Func[18] = Calculator::dblMinusLln;
    Func[19] = Calculator::dblMultiLln;
    Func[20] = Calculator::dblDivisLln;
    Func[21] = Calculator::llnAssignedToDbl;
    Func[22] = Calculator::dblAssignedToLln;
    Func[23] = Calculator::nelln;
    Func[24] = Calculator::nedbl;
}

void Calculator::fsum()
{
    int n = 0;
    double dbl;

    DCell tmpCell, sumCell;

    cin>>n;

    sumCell.setValue(0.0);
    for(int i = 0; i < n; i++)
    {
        cin>>dbl;
        tmpCell.setValue(dbl);
        sumCell += tmpCell;
    }

    printf("%.4f\n", sumCell.getValue());
}

void Calculator::nsum()
{
    int n = 0;
    long long lln;
    NCell tmpCell, sumCell;

    cin>>n;

    sumCell.setValue(0);
    for(int i = 0; i < n; i++)
    {
        cin>>lln;
        tmpCell.setValue(lln);
        sumCell += tmpCell;
    }

    cout<<sumCell.getValue()<<endl;
}

void Calculator::twollnPlus()
{
    long long ll1, ll2;
    cin>>ll1>>ll2;

    NCell nc1(ll1), nc2(ll2);
    nc1 = nc1 + nc2;

    cout<<nc1.getValue()<<endl;

}

void Calculator::twollnMinus()
{
    long long ll1, ll2;
    cin>>ll1>>ll2;

    NCell nc1(ll1), nc2(ll2);
    nc1 = nc1 - nc2;

    cout<<nc1.getValue()<<endl;

}

void Calculator::twollnMulti()
{
    long long ll1, ll2;
    cin>>ll1>>ll2;

    NCell nc1(ll1), nc2(ll2);
    nc1 = nc1 * nc2;

    cout<<nc1.getValue()<<endl;
}

void Calculator::twollnDivis()
{
    long long ll1, ll2;
    cin>>ll1>>ll2;

    NCell nc1(ll1), nc2(ll2);
    nc1 = nc1 / nc2;

    cout<<nc1.getValue()<<endl;
}

void Calculator::twollnPlusEq()
{
    long long ll1, ll2;
    cin>>ll1>>ll2;

    NCell nc1(ll1), nc2(ll2);
    nc1 += nc2;

    cout<<nc1.getValue()<<endl;
}

void Calculator::twodblPlus()
{
    double db1, db2;
    cin>>db1>>db2;

    DCell dc1(db1), dc2(db2);
    dc1 = dc1 + dc2;

    printf("%.4f\n", dc1.getValue());
}

void Calculator::twodblMinus()
{
    double db1, db2;
    cin>>db1>>db2;

    DCell dc1(db1), dc2(db2);
    dc1 = dc1 - dc2;

    printf("%.4f\n", dc1.getValue());
}

void Calculator::twodblMulti()
{
    double db1, db2;
    cin>>db1>>db2;

    DCell dc1(db1), dc2(db2);
    dc1 = dc1 * dc2;

    printf("%.4f\n", dc1.getValue());
}

void Calculator::twodblDivis()
{
    double db1, db2;
    cin>>db1>>db2;

    DCell dc1(db1), dc2(db2);
    dc1 = dc1 / dc2;

    printf("%.4f\n", dc1.getValue());
}

void Calculator::twodblPlusEq()
{
    double db1, db2;
    cin>>db1>>db2;

    DCell dc1(db1), dc2(db2);
    dc1 += dc2;

    printf("%.4f\n", dc1.getValue());
}

void Calculator::llnPlusDbl()
{
    long long ll1;
    double db1;
    cin>>ll1>>db1;
    NCell nc1(ll1);
    DCell dc1(db1);
    nc1 = nc1 + dc1;

    cout<<nc1.getValue()<<endl;
}

void Calculator::llnMinusDbl()
{
    long long ll1;
    double db1;
    cin>>ll1>>db1;
    NCell nc1(ll1);
    DCell dc1(db1);
    nc1 = nc1 - dc1;

    cout<<nc1.getValue()<<endl;
}

void Calculator::llnMultiDbl()
{
    long long ll1;
    double db1;
    cin>>ll1>>db1;
    NCell nc1(ll1);
    DCell dc1(db1);

    nc1 = nc1 * dc1;

    cout<<nc1.getValue()<<endl;
}

void Calculator::llnDivisDbl()
{
    long long ll1;
    double db1;
    cin>>ll1>>db1;
    NCell nc1(ll1);
    DCell dc1(db1);

    nc1 = nc1 / dc1;

    cout<<nc1.getValue()<<endl;
}

void Calculator::dblPlusLln()
{
    double db1;
    long long ll1;
    cin>>db1>>ll1;

    DCell dc1(db1);
    NCell nc1(ll1);
    dc1 = dc1 + nc1;

    printf("%.4f\n", dc1.getValue());
}

void Calculator::dblMinusLln()
{
    double db1;
    long long ll1;
    cin>>db1>>ll1;

    DCell dc1(db1);
    NCell nc1(ll1);
    dc1 = dc1 - nc1;

    printf("%.4f\n", dc1.getValue());
}

void Calculator::dblMultiLln()
{
    double db1;
    long long ll1;
    cin>>db1>>ll1;

    DCell dc1(db1);
    NCell nc1(ll1);
    dc1 = dc1 * nc1;

    printf("%.4f\n", dc1.getValue());
}

void Calculator::dblDivisLln()
{
    double db1;
    long long ll1;
    cin>>db1>>ll1;

    DCell dc1(db1);
    NCell nc1(ll1);
    dc1 = dc1 / nc1;

    printf("%.4f\n", dc1.getValue());
}

void Calculator::llnAssignedToDbl()
{
    long long ll1;
    cin>>ll1;
    NCell nc1(ll1);

    DCell dc1 = nc1;

    printf("%.4f\n", dc1.getValue());
}

void Calculator::dblAssignedToLln()
{
    double db1;
    cin>>db1;
    DCell dc1(db1);

    NCell nc1 = dc1;

    cout<<nc1.getValue()<<endl;
}

void Calculator::nelln()
{
    long long val;
    cin>>val;
    NCell nc(val);

    cout<<(-nc).getValue()<<endl;

}

void Calculator::nedbl()
{
    double val;
    cin>>val;
    DCell dc(val);

    cout<<(-dc).getValue()<<endl;
}

int Calculator::DecodeFuncIdx(unsigned code)
{
    unsigned cd = 1;
    for(int i = 1; i < 25; i++)
    {
        if(cd == code) return i;
        cd = cd<<1;
    }

    return -1;
}



int main()
{
    Calculator::init();

    unsigned code = 0;
    std::cin >> code;
    int op = Calculator::DecodeFuncIdx(code);

    if(op < 1 || op > 24)
    {
        return 1;
    }

    Calculator::Func[op]();

    return 0;
}
