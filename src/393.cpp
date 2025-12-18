#include <iostream>
#include <string>
using namespace std;
class BirthDate {
public:
    BirthDate(int,int,int);
    void display();
    void setbirthday(int,int,int);
    int getAge();
private:
    int year;
    int month;
    int day;
};
class Teacher
{
public:
    Teacher(int,string,char);
    void display();
private:
    int num;
    string name;
    char sex;
};


// ____qcodep____
class Professor : public Teacher
{
public:
    Professor(int,string,char,BirthDate);
    void display();
    void setbirthday(int,int,int);
    void showAge();
private:
    BirthDate birthday;
};

BirthDate::BirthDate(int y,int m,int d)
{
    year=y;month=m;day=d;
}

int BirthDate::getAge(){
    time_t rawtime;
    struct tm *info;
    char buffer[80];

    time( &rawtime );

    info = localtime( &rawtime );

    int nd = info->tm_mday;
    int nm = info->tm_mon+1;
    int ny = info->tm_year+1900;
    //为了防止每年都要调整校验数据，此处设置固定的时间。
    //相当于此程序运行的时间固定为2020-5-21
    nd=21;
    nm=5;
    ny=2020;

    // ____qcodep____
    int age = ny - year;
    if (nm < month || (nm == month && nd < day)){
        age--;
    }
    return age;
}

void BirthDate::display()
{
    cout<<"birthday:"<<year<<"/"<<month<<"/"<<day<<endl;
}

void BirthDate::setbirthday(int y,int m,int d)
{
    year=y;month=m;day=d;
}
Teacher::Teacher(int n ,string nam ,char c)
{
    num=n;
    name=nam;
    sex=c;
}
void Teacher::display()
{
    cout<<"num:"<<num<<endl;
    cout<<"name:"<<name<<endl;
    cout<<"sex:"<<sex<<endl;
}

// ____qcodep____

Professor::Professor(int n, string nam, char c, BirthDate b) : Teacher(n, nam, c), birthday(b) {}
void Professor::setbirthday(int y, int m, int d){
    birthday.setbirthday(y, m, d);
}

void Professor::display()
{
    Teacher::display();
    birthday.display();

}
void Professor::showAge(){
    cout<<"age:"<<birthday.getAge()<<endl;
}

// ____qcodep____

int main()
{
    int num;
    string name;
    char sex;
    int year,month,day;
    cin>>num>>name>>sex;
    cin>>year>>month>>day;
    Professor prof(num,name,sex,BirthDate(year,month,day));
    cin>>year>>month>>day;
    prof.setbirthday(year,month,day);
    prof.display();
    prof.showAge();
    return 0;
}
