#include <iostream>
using namespace std;

// ____qcodep____

class TimeSavings;

//声明活期储蓄类
class CurrentSavings
{
private:
    int balance;

public:
    CurrentSavings (int balance){
        // ____qcodep____ 
        this->balance = balance;       
    }
    // ____qcodep____ 
    void print(){
        cout << this->balance << endl;
    }
    friend void printTotalSavings(TimeSavings &ts, CurrentSavings &cs);
};

//声明定期储蓄类
class TimeSavings
{
private:
    int balance;

public:
    TimeSavings(int balance){
        // ____qcodep____
        this->balance = balance;
    }
    // ____qcodep____
    void print(){
        cout << this->balance << endl;
    }
    friend void printTotalSavings(TimeSavings &ts, CurrentSavings &cs);
};


void printTotalSavings(TimeSavings &ts, CurrentSavings &cs)
{
    // ____qcodep____
    cout << ts.balance + cs.balance << endl;
}

int main(void)
{
    int cs, ts;
    cin >> cs >> ts;

    CurrentSavings cs1(cs);
    TimeSavings ts1(ts);

    cs1.print();
    ts1.print();
    printTotalSavings(ts1, cs1);

    return 0;
}
