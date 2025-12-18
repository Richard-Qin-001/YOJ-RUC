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
    // ____qcodep____
    string getName() { return name; }

private:
    int num;
    string name;
    char sex;
};


class Professor: private Teacher
{
public:
    // Professor(int a, string b, char c, BirthDate d)____qcodep____
    Professor(int a, string b, char c, BirthDate d) : Teacher(a, b, c), birthday(d) {}
    void display()
    {
        Teacher::display();
        cout << Teacher::getName() << " is a professor whose birthday is ";
        birthday.display();
    }

    void setbirthday(int y, int m, int d)
    {
        birthday.setbirthday(y, m, d);
    }

private:
    BirthDate birthday;
};
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
    prof.display();
    cin>>year>>month>>day;
    prof.setbirthday(year,month,day);
    cout << "\nAfter setbirthday:" << endl;
    prof.display();
    cout << sizeof(prof) << endl;
    return 0;
}
