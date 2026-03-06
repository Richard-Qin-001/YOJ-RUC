#include <iostream>
#include "calculator.h"
#include "dcell.h"
#include "ncell.h"

using namespace std;

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
