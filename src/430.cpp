#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>

using namespace std;

class complex {
public:
//complex (double r, double i): real(r), img(i){}

//复数求模
    double getModules() const{
        return sqrt(real*real + img * img);
    }
//设置实部和虚部
    void setReal(double r) {real = r;}
    void setImg(double i){img = i;}

    //将复数转换为字符串的形式。输出复数时，请调用此函数
    string toString() const{
        string s = "";
        s += to_string(this->real);
        s += " + ";
        s += to_string(this->img);
        s += "i";
        return s;
    }
private:
    double real;//复数的实部
    double img;//复数的虚部

};

template <class T>
void swap (T * p1, T * p2){
    T temp = * p1;
    * p1 = * p2;
    * p2 = temp;
}


/*
下面的函数实现对一组数据的排序。
参数 isLargerThan 是一个函数指针，要求对两个数据 t1 和 t2 进行比较，若t1 大于 t2，返回true； 否则返回 false。
ascending 表示是否按升序排序，默认为 true
*/
template <class T>
void sort(T * array, int count, bool (* isLargerThan)(const T & t1, const T & t2), bool ascending = true){

//学生填空开始
//   ____qcodep____

    for(int i = 0; i < count - 1; ++i){
        for (int j = 0; j < count - i - 1; ++j){
            bool larger = isLargerThan(array[j], array[j + 1]);
            if ((ascending && larger) || (!ascending && !larger)){
                swap(&array[j], &array[j+1]);
            }
        }
    }
    

  // 学生填空结束
}


//下面的函数打印一个数组，count为数组元素个数，printT为打印一个元素的函数
template <class T>	//定义函数模板
void outputArray(const T *array, int count, void (* printT)(const T &)) {

// 学生填空开始

// ____qcodep____

for (int i = 0; i < count; i++)
{
    printT(array[i]);
}

// 学生填空结束
}


// 学生填空开始
// ____qcodep____

bool compareComplex(const complex &c1, const complex &c2)
{
    return c1.getModules() > c2.getModules();
}

void printComplex(const complex &c)
{
    cout << c.toString() << endl;
}

bool compareString(const string &s1, const string &s2)
{
    return s1.length() > s2.length();
}

void printString(const string &s)
{
    cout << s << endl;
}

// 学生填空结束

int main()
{

    complex cnums[3];
   //读入 3 个复数
    cout<<"分３行输入３个复数，每行分别输入一个复数的实部和虚部，按空格隔开:\n";
    double x, y;
    int i;
    for (i=0;i<3;i++){
        cin>>x>>y;
        cnums[i].setReal(x);
        cnums[i].setImg(y);
}

   //将这三个复数按降序排列
    sort(cnums, 3, compareComplex, false);
   //将排序后的复数数组输出
   cout<<"将３个复数按降序排列的结果：\n";
   outputArray(cnums, 3, printComplex);

    string strs[3];
   //读入三个字符串
   cout<<"依次输入３个字符串，以空格或回车隔开:\n";
    for(i=0;i<3;i++){
        cin>>strs[i];
    }

    //将三个字符串按升序排列
    sort(strs, 3, compareString);
    //将排序后的字符串数组输出
    cout<<"将３个字符串按长度升序排列后的结果：\n";
outputArray(strs, 3, printString);

 


    return 0;
}

