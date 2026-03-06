#ifndef DCELL_H
#define DCELL_H
#include <string>

class NCell;
class DCell
{
public:
    DCell();
    DCell(double value);
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

private:
    double dvalue;

};

DCell operator-(const DCell &obj);

#endif // DCELL_H
