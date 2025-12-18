#include <iostream>

using namespace std;
class person{
    string name;
    int age;
public:
    person(string na,int d);
    string getName();//获取姓名
    int getAge();//获取年龄 
    // ____qcodep____
    friend int compare(person &s1, person &s2);
};

// ____qcodep____
person::person(string na, int d) : name(na), age(d) {}
string person::getName(){
    return this->name;
}
int person::getAge(){
    return this->age;
}

int compare(person &s1,person &s2)
{
    if( s1.age == s2.age )
        return 0;
    else if( s1.age > s2.age )
        return 1;
    else
    {
        return -1;
    }
    
}

int main(){
    string name1, name2, name3;
    int age1, age2, age3;
    cin >> name1 >> age1;
    cin >> name2 >> age2;
    cin >> name3 >> age3;

    // ____qcodep____
    person ps[3] = {person(name1, age1), person(name2, age2), person(name3, age3)};

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
            cout << "Age:" << ps[j].getAge() << " Name:" << ps[j].getName() << endl;
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
        
        if (ps[middle].getAge() == ps[max].getAge()){
            cout << "Maximum age:" << ps[max].getAge() << " Name:" << ps[max].getName() << endl;
            cout << "Maximum age:" << ps[middle].getAge() << " Name:" << ps[middle].getName() << endl;
            cout << "Minimum age:" << ps[min].getAge() << " Name:" << ps[min].getName() << endl;
        }else if(ps[middle].getAge() == ps[min].getAge()){
            cout << "Maximum age:" << ps[max].getAge() << " Name:" << ps[max].getName() << endl;
            cout << "Minimum age:" << (ps[min]).getAge() << " Name:" << ps[min].getName() << endl;
            cout << "Minimum age:" << ps[middle].getAge() << " Name:" << ps[middle].getName() << endl;
        } else{
            cout << "Maximum age:" << ps[max].getAge() << " Name:" << ps[max].getName() << endl;
            cout << "Minimum age:" << ps[min].getAge() << " Name:" << ps[min].getName() << endl;
        }

    }

    return 0;
}
