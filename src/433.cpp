#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
using namespace std;

class complex
{
public:
    //复数求模
    double getModules() const
    {
        return sqrt(real * real + img * img);
    }
    //设置实部和虚部
    void setReal(double r) { real = r; }
    void setImg(double i) { img = i; }

    //将复数转换为字符串的形式。输出复数时，请调用此函数
    string toString() const
    {
        string s = "";
        s += to_string(this->real);
        s += " + ";
        s += to_string(this->img);
        s += "i";
        return s;
    }

private:
    double real; //复数的实部
    double img;  //复数的虚部
};

/*
排序函数模板
下面的函数模板实现对一组数据的排序。
参数 cmp 是一个函数指针，要求对两个数据 t1 和 t2 进行比较，若t1 大于 t2，返回true； 否则返回 false。
ascending 表示是否按升序排序，默认为 true
*/
//    ____qcodep____

template <class T>
void swap(T *p1, T *p2)
{
    T temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

template <class T>
void mysort(T *array, int count, bool (*isLargerThan)(const T &t1, const T &t2), bool ascending = true){
    for (int i = 0; i < count - 1; ++i){
        for (int j = 0; j < count - i - 1; ++j){
            bool larger = isLargerThan(array[j], array[j + 1]);
            if ((ascending && larger) || (!ascending && !larger))
            {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

bool compareComplex(const complex &t1, const complex &t2)
{
    return t1.getModules() > t2.getModules();
}
bool compareString(const string &t1, const string &t2)
{
    return t1 > t2;
}

//下面的函数打印一个数组，count为数组元素个数，printT为打印一个元素的函数
template <class T> //定义函数模板
void outputArray(const T *array, int count, void (*printT)(const T &))
{
    for (int i = 0; i < count; i++)
    {
        printT(array[i]);
        cout << endl;
    }
}



void printComplex(const complex & c){
    cout << c.toString();
}
void printString(const string & s){
    cout << s;
}

template void mysort<complex>(complex *array, int count, bool (*cmp)(const complex &t1, const complex &t2), bool ascending = true);

int main()
{
    complex cnums[3];
    double x, y;
    int i;
    for (i = 0; i < 3; i++)
    {
        cin >> x >> y;
        cnums[i].setReal(x);
        cnums[i].setImg(y);
    }
    mysort(cnums, 3, compareComplex, false);
    outputArray(cnums, 3, printComplex);

    string strs[3];
    for (i = 0; i < 3; i++)
    {
        cin >> strs[i];
    }

    mysort(strs, 3, compareString);
    outputArray(strs, 3, printString);

    return 0;
}
