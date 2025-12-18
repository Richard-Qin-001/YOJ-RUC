#include<string>
#include <iostream>
using namespace std;

// ____qcodep____

class Person{
protected:
    string name;
    int age;
    char sex;
    string addr;
    string tel;

public:
    Person(string nam, int a, char s, string ad, string t)
        : name(nam), age(a), sex(s), addr(ad), tel(t) {}
};

class Teacher : virtual public Person
{
public:
    Teacher(string nam, int a, char s, string tit, string ad, string t)
        : Person(nam, a, s, ad, t), title(tit) {}
    void display();

protected:
    string title;
};

class Cadre : virtual public Person
{
public:
    Cadre(string nam, int a, char s, string p, string ad, string t)
    : Person(nam, a, s, ad, t), post(p) {}
    void display();

protected:
    string post;
};

class Teacher_Cadre : public Teacher, public Cadre
{
public:
    Teacher_Cadre(string nam, int a, char s, string tit, string p, string ad, string t, double w)
        : Person(nam, a, s, ad, t), Teacher(nam, a, s, tit, ad, t), Cadre(nam, a, s, p, ad, t), wage(w) {}
    void show();

private:
    double wage;
};


//end 


void Teacher::display()
{
    cout<<"name:"<<name<<endl;
    cout<<"age:"<<age<<endl;
    cout<<"sex:"<<sex<<endl;
    cout<<"title:"<<title<<endl;
    cout<<"address:"<<addr<<endl;
    cout<<"tel:"<<tel<<endl;
}

void Cadre::display()
{
    cout<<"name:"<<name<<endl;
    cout<<"age:"<<age<<endl;
    cout<<"sex:"<<sex<<endl;
    cout<<"post:"<<post<<endl;
    cout<<"address:"<<addr<<endl;
    cout<<"tel:"<<tel<<endl;
}

void Teacher_Cadre ::show()
{
    Teacher::display();
    cout<<"post:"<<post<<endl;
    cout<<"wages:"<<wage<<endl;
}

int main()
{
    string name,title,post,address,tele;
    int age;
    char sex;
    float wages;
    cin>>name>>age;
    cin>>sex>>title>>post;
    getline(cin,address);
    cin>>tele>>wages;
    Teacher_Cadre te_ca(name,age,sex,title,post,address,tele,wages);
    te_ca.show();
    
    cout << sizeof(Teacher) << endl;
    cout << sizeof(Cadre) << endl;
    cout << sizeof(Teacher_Cadre) << endl;

    return 0;
}
