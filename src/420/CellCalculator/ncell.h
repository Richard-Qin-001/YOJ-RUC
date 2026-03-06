#ifndef NCELL_H
#define NCELL_H

class DCell;
class NCell
{
public:
    NCell();
    NCell(long long value);
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

private:
    long long llvalue;

};

NCell operator-(const NCell &obj);

#endif // NCELL_H
