#include <iostream>

using namespace std;
class person{
    string name;
    int age;
public:
    person(string na,int d);
    string getname();//获取姓名
    friend int compare(person &s1,person &s2);//比较两人年龄
    int getage();//获取年龄
};

// ____qcodep____
person::person(string na, int d) : name(na), age(d) {}
string person::getname(){
    return this->name;
}
int person::getage(){
    return this->age;
}
int compare(person&s1, person&s2){
    if(s1.age > s2.age)return 1;
    if(s1.age < s2.age)return -1;
    return 0;
}

int main(){
    string name1, name2, name3;
    int age1, age2, age3;

    cin >> name1 >> age1;
    cin >> name2 >> age2;
    cin >> name3 >> age3;
    person ps[3]={person(name1,age1),person(name2,age2),person(name3,age3)};
    int i=0,min=0,max=0;
    for(i=1;i<3;i++){
        if(compare(ps[max],ps[i])==-1)
            max=i;
        if(compare(ps[min],ps[i])==1)
            min=i;
    }

    if(min==max){
        cout << "They are all in the same age" << endl;
        for (int j = 0; j < 3; ++j) {
            cout << "Age:" << ps[j].getage() << " Name:" << ps[j].getname() << endl;
        }
    }else{   //找到中间值的下标
        int middle;
        for(int j=0;j<3;j++)
        {
            if(j!=max && j!=min)
            {
                middle=j;
            }
        }
        
        if (ps[middle].getage() == ps[max].getage()){
            cout << "Maximum age:" << ps[max].getage() << " Name:" << ps[max].getname() << endl;
            cout << "Maximum age:" << ps[middle].getage() << " Name:" << ps[middle].getname() << endl;
            cout << "Minimum age:" << ps[min].getage() << " Name:" << ps[min].getname() << endl;
        }else if(ps[middle].getage() == ps[min].getage()){
            cout << "Maximum age:" << ps[max].getage() << " Name:" << ps[max].getname() << endl;
            cout << "Minimum age:" << (ps[min]).getage() << " Name:" << ps[min].getname() << endl;
            cout << "Minimum age:" << ps[middle].getage() << " Name:" << ps[middle].getname() << endl;
        } else{
            cout << "Maximum age:" << ps[max].getage() << " Name:" << ps[max].getname() << endl;
            cout << "Minimum age:" << ps[min].getage() << " Name:" << ps[min].getname() << endl;
        }

    }

    return 0;
}
