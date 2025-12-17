#include<iostream>
#include<string>
using namespace std;

class Date {
    int year;
    int month;
    int day;
public:
    Date(int y, int m, int d): year(y), month(m), day(d) { }
    void display() { cout<<year << '-' << month << '-' << day << endl; }
    void setDate(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }
};

class Person {
    int id;
    string name;
    char gender;
    Date birthday;
public:
    // ____qcodep____
    Person(int id, string name, char gender, int y, int m, int d): id(id), name(name), gender(gender), birthday(y, m, d) {
        nPerson++;
    }
    ~Person() { nPerson--; }
    void display();
    
    friend int findPerson(Person **pp, int numOfPersons, int id);
private:
    static int nPerson;
public:
    static void showCount() {
        cout << "Number of persons in total: " << nPerson << endl;
    };
};
// ____qcodep____
int Person::nPerson = 0;

void Person::display(){
    cout << id << " " << name << " " << gender << " ";
    birthday.display();
}

int findPerson(Person **pp, int numOfPersons, int id){
    for(int i = 0; i < numOfPersons; ++i){
        if(pp[i]->id == id)return i;
    }
    return -1;
}


int main() {
    int numOfPersons;
    cin>>numOfPersons;
    Person **pp = new Person* [numOfPersons];
    for (int i=0; i<numOfPersons; i++) {
        int id;
        string name;
        char gender;
        int year, month, day;
        cin>>id>>name>>gender>>year>>month>>day;
        pp[i] = new Person(id, name, gender, year, month, day);
    }
    int id;
    cin>>id;
    int index = findPerson(pp, numOfPersons, id);
    Person::showCount();
    if (index<0) {
        cout<<"Not found."<<endl;
    } else {
        pp[index]->display();
    }

    for (int i=0; i<numOfPersons; i++) {
        delete pp[i];  //!Attention!
    }
    delete [] pp;
    Person::showCount();
    return 0;
}