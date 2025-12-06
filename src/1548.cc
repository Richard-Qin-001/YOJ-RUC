#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input;
    getline(cin, input);

    stringstream ss(input);
    string s1, s2, s3, s4;
    getline(ss, s1, ',');
    getline(ss, s2, ',');
    getline(ss, s3, ',');
    getline(ss, s4, ',');

    int decInt = stoi(s1);
    int hexInt = stoll(s2, nullptr, 16);
    string str = s3;
    double f = stod(s4);

    cout << setw(15) << right << decInt << "\n";
    cout << setw(15) << left << hexInt << "\n";
    cout << setw(15) << right << str << "\n";
    cout << setw(15) << left << fixed << setprecision(2) << f << "\n";
    return 0;
}