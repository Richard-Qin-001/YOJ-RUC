# include <iostream>
# include <string>
# include <iomanip>

int main(){
    using namespace std;
    int int1, int2;
    double double1, double2;
    char ch;
    string str;
    cin >> int1 >> ch >> int2 >> double1 >> double2;
    cin.ignore();
    getline(cin, str);
    cout << int1 << ch << int2 << endl;
    cout << fixed << setprecision(1) << double1 << ' ' << double2 << endl;
    cout << str << endl;
    return 0;
}
// 注意事项：
// 1. 使用 cin.ignore() 来忽略换行符，确保 getline 能正确读取字符串。
// 2. 使用 fixed 和 setprecision 来控制浮点数的输出格式。
