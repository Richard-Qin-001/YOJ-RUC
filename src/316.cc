#include <iostream>
#include <vector>


using namespace std;

void solve(){
    vector<string> week = { "SUN", "MON","TUE", "WED", "THU", "FRI", "SAT"};
    int date = 0;
    cin >> date;
    date = (date - 1) % 7;
    cout << week[date]  << endl;
}
int main(){solve(); return 0;}