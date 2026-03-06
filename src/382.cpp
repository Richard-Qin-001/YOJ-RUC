#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

const double RATIO = 0.01;
const double SALARY_PER_YEAR = 35;
const double BASE_SALARY = 1000;

// ____qcodep____
class Person
{
protected:
    int workAge;
public:
    Person(int age) : workAge(age) {}
    virtual double getPayPerMonth() = 0;
    virtual ~Person() {}
};

class Worker : public Person
{
protected:
    double salaryPerHour;
    int workHour;

public:
    Worker(int age) : Person(age), salaryPerHour(0), workHour(0) {}

    void setSalaryPerHour(double s) { salaryPerHour = s; }
    void setWorkHour(int h) { workHour = h; }

    double getPayPerMonth() override
    {
        return salaryPerHour * workHour + workAge * SALARY_PER_YEAR;
    }
};


class SalesPerson : public Worker
{
protected:
    double salesAmount;

public:
    SalesPerson(int age) : Worker(age), salesAmount(0) {}

    void setSalesAmount(double s) { salesAmount = s; }

    double getPayPerMonth() override
    {
        return Worker::getPayPerMonth() + salesAmount * RATIO;
    }
};

class Manager : public Person
{
public:
    Manager(int age) : Person(age) {}

    double getPayPerMonth() override
    {
        return BASE_SALARY + workAge * SALARY_PER_YEAR;
    }
};

int main(){
    //Person* per = 0;
    int workAge1,workAge2,workAge3;
    double salaryPerHour1,salaryPerHour2;
    int workHour1,workHour2;
    double salesAmount;

    cin>>workAge1>>workAge2>>workAge3;
    cin>>salaryPerHour1>>salaryPerHour2;
    cin>>workHour1>>workHour2;
    cin>>salesAmount;

    Worker* p = new Worker(workAge1);
    p->setSalaryPerHour(salaryPerHour1);
    p->setWorkHour(workHour1);
    cout<<p->getPayPerMonth()<<endl;
    delete p;

    SalesPerson* sp = new SalesPerson(workAge2);
    sp->setSalaryPerHour(salaryPerHour2);
    sp->setWorkHour(workHour2);
    sp->setSalesAmount(salesAmount);
    cout<<sp->getPayPerMonth()<<endl;
    delete sp;

    Manager* mgr = new Manager(workAge3);
    cout<<mgr->getPayPerMonth()<<endl;
    delete mgr;
    return 0;
}