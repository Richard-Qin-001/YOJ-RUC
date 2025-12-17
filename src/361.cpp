#include <iostream>
using namespace std;
//此处可补充代码
// ____qcodep____

class Date {
    public:
        Date(int year = 1900, int month = 1, int day = 1);
        Date(const Date& date);
        void show();
    private:
        int _year;
        int _month;
        int _day;
        bool _good;
        //此处可补充代码
        // ____qcodep____
        #define OUTPUT
        friend void printDate(const Date &date);
};
//此处可补充代码
// ____qcodep____
Date::Date::Date(int year, int month, int day)
{
    _good = true;
    if(year < 0)_good = false;
    if(month < 1 || month > 12)_good = false;
    else
    {
        int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))days[2] = 29;
        if(day < 1 || day > days[month])_good = false;
    }
    if(!_good)cout << "The date is illegal!" << endl;
    else {
        _year = year, _month = month, _day = day;
    }
}
Date::Date(const Date &date)
{
    if(!date._good){
        cout << "The date is illegal!" << endl;
    }
    else{
        _year = date._year;
        _month = date._month;
        _day = date._day;
        _good = date._good;
    }
}
void Date::show()
{
    if (!_good)
        cout << "Error date format!\n";
    else
         cout << _year << '-' << _month << '-' << _day << endl;
    return;
}

#ifdef OUTPUT
void printDate(const Date& date)
{
    if (!date._good)
        cout << "Error date format!" << endl;
    else
        cout << date._year << "/" << date._month << "/" << date._day << endl;
    return;;
    
}
#endif

int main()
{
    int y, m, d, flag;
    cin >> flag >> y >> m >> d;
    cout << y << " " << m << " " << d << endl;
    Date date1(y,m,d), date2(date1);
    if (flag)
    {
    #ifdef OUTPUT
        printDate(date1);
    #endif
    }else{
        date1.show();
    }
    return 0;
}