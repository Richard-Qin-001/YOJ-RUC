#include <iostream>
#include <string>
using namespace std;

class Student
{
    string name;
    int age;

public:
    // 此处补充Student类的构造函数
    // 保证后面的主函数正确运行
    // 注意：默认情况下，age初始化为0，name初始化为NONE
// ____qcodep____
    Student(int a = 0, string n = "NONE") : age(a), name(n) {}
    //输出信息
    void show()
    {
        cout << name << ": " << age << endl;
    }
};

int main()
{
    int num;
    string str;
    cin >> num >> str; //读入年龄和姓名
    Student st(num, str);
    Student *p = new Student();
    st.show();
    p->show();
    return 0;
}