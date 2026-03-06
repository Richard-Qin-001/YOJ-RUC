#include <iostream>
#include "dcell.h"
#include "ncell.h"

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

DCell::DCell(const NCell &other)
{
    dvalue = static_cast<double> (other.getValue());
}

DCell operator-(const DCell &obj)
{
    return DCell(-obj.getValue());
}
