#include <iostream>
#include "ncell.h"
#include "dcell.h"

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

NCell::NCell(const DCell &other)
{
    llvalue = static_cast<long long> (other.getValue());
}

NCell operator-(const NCell &obj)
{
    return NCell(-obj.getValue());
}
