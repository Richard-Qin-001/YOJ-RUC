#include <iostream>
#include <string>
using namespace std;

class BirthDate
{
public:
    BirthDate(int y, int m, int d):year(y), month(m), day(d) {}
    void display(){
        cout << "Birthday: " << year << "-" << month << "-" << day << endl;
    }
    void setbirthday(int y, int m, int d){
        year = y, month = m, day = d;
    };
private:
    int year;
    int month;
    int day;
};

class Teacher
{
public:
    Teacher(int id, string nam, char se):num(id), name(nam), sex(se) {}
    void display(){
        cout << "Teacher info: " << num << "/" << name << "/" << sex << endl;

    }
protected:
    int num;
    string name;
    char sex;
};


class Professor: private Teacher
{
public:
// ____qcodep____
    Professor(int id, string nam, char se, BirthDate bd)
        : Teacher(id, nam, se), birthday(bd) {}
    void display(){
        Teacher::display();
        cout << name << " is a professor whose birthday is ";
        birthday.display();
    }
    void setbirthday(int y, int m, int d)
    {
        birthday.setbirthday(y, m, d);
    }

private:
    BirthDate birthday;
};



int main()
{
    int num;
    string name;
    char sex;
    int year,month,day;
    cin>>num>>name>>sex;
    cin>>year>>month>>day;
    Professor prof(num,name,sex,BirthDate(year,month,day));
    prof.display();
    cin>>year>>month>>day;
    prof.setbirthday(year,month,day);
    cout << "\nAfter setbirthday:" << endl;
    prof.display();
    cout << sizeof(prof) << endl;
    return 0;
}