#include <iostream>
#include "calculator.h"
#include "calculator.cpp"
#include "ncell.cpp"
#include "dcell.cpp"

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
