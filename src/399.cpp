#include <iostream>
using namespace std;
// ____qcodep____

template <typename T>
class CArray3D{
private:
    T *data;
    int dim1, dim2, dim3;

    class CArray2D
    {
    private:
        T *p2;
        int d3;
    public:
        CArray2D(T *p, int d) : p2(p), d3(d) {}
        T *operator[](int j){return p2 + j * d3;}
    };

public:
    CArray3D(int d1, int d2, int d3) : dim1(d1), dim2(d2), dim3(d3)
    {
        data = new T[d1 * d2 * d3];
    }

    ~CArray3D(){
        if (data)
            delete[] data;
    }

    CArray2D operator[](int i){
        return CArray2D(data + i * dim2 * dim3, dim3);
    }
};

int main()
{
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";

    CArray3D<char> b(3,4,5);
    char c = 'A';
    for( int i = 0; i < 3; ++i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                b[i][j][k] = c++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << b[i][j][k] << ",";

    return 0;
}