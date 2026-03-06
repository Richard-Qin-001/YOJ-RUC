#ifndef CALCULATOR_H
#define CALCULATOR_H

typedef void (*CalFunc)();

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

#endif // CALCULATOR_H
