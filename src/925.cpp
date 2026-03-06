/*
函数指针的使用：
编写一个乘法函数，该函数输入两个int类型的参数，并返回这两个数的乘积。
在主函数中，每次输入两个int类型的参数x和y，使用函数指针调用上述乘法函数，并打印x和y的乘积。

输入样例：
2
3 6
5 8

第一行表示初始变量n=2。接下来有n行，每一行有两个int类型的参数。

对应的输出为：
18
40

共有n行输出，每一行输出为一个数，为对应输入行的两个数的乘积。
*/

#include <iostream>
using namespace std;

int multiply(int x, int y)
{
    // ____qcodep____
    return x*y;
}

int main()
{
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;

        // ____qcodep____
        int (*f)(int, int) = multiply;

        cout << f(x, y) << endl;
    }
}