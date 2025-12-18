#include<string>
#include <iostream>

using namespace std;
class Teacher
{
public:
    Teacher(string nam,int a,char s,string tit,string ad,string t);
    void display();
protected:
    string name;
    int age;
    char sex;
    string title;
    string addr;
    string tel;
};

class Cadre
{
public:
    Cadre(string nam,int a,char s,string p,string ad,string t);
    void display();
protected:
    string name;
    int age;
    char sex;
    string post;
    string addr;
    string tel;
};

// ____qcodep____//定义类

class Teacher_Cadre : public Teacher, public Cadre {
public:
    Teacher_Cadre(string nam, int a, char s, string tit, string p, string ad, string t, float w);
    void show();
private:
    float wage;
};

Teacher::Teacher(string nam, int a, char s, string tit, string ad, string t)
{
    name=nam;
    age=a;
    sex=s;
    title=tit;
    addr=ad;
    tel=t;
}

Cadre::Cadre(string nam,int a,char s,string p,string ad,string t)
{
    name=nam;
    age=a;
    sex=s;
    post=p;
    addr=ad;
    tel=t;
}

// ____qcodep____//构造函数
Teacher_Cadre::Teacher_Cadre(string nam, int a, char s, string tit, string p, string ad, string t, float w)
    : Teacher(nam, a, s, tit, ad, t), Cadre(nam, a, s, p, ad, t), wage(w){}

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
    cout<<"post:"<<Cadre::post<<endl;
    cout<<"wages:"<<wage<<endl;
}

int main( )
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
    te_ca.show( );
    return 0;
}
