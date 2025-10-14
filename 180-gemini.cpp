#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// 函数：计算 sin(x) 的近似值
double calculate_sin(double x, double epsilon) {
    // 确保 x 在 [0, 2*pi) 范围内可以简化计算，但对于泰勒级数收敛性没有绝对必要，
    // 这里为通用性保留原始 x。不过，将 x 规范化到 [-pi, pi] 可以减少 x 的幂次增长，
    // 从而提高计算的数值稳定性。
    // double x_normalized = fmod(x, 2.0 * M_PI); 
    // M_PI 是 <cmath> 中定义的圆周率。由于题目要求简单实现，我们直接使用 x。

    // 第一项: x^1 / 1! = x
    double term = x; 
    double sum = term;
    long long n = 1; // n 表示级数项的索引，对应于 (2n+1)!，从 1 开始代表下一项的幂次是 3

    // 循环条件: 当前项的绝对值大于等于 epsilon，继续计算下一项
    // 对应于 (2n+1)! 的指数为 2n+1
    while (abs(term) >= epsilon) {
        // 计算下一项的递推关系:
        // 当前项是 (-1)^(n-1) * x^(2n-1) / (2n-1)!
        // 下一项是 (-1)^n * x^(2n+1) / (2n+1)!
        // 下一项 = 当前项 * (-1) * x^2 / ((2n+1) * (2n))
        // 这里的 n 是从 1 开始的迭代次数，但它与级数中的 n (从 0 开始) 不同
        // 在循环中，n 相当于级数公式中分母的 (2k+1)! 的 k 的值，k从 1 开始。
        // 对于 (2n+1) 和 (2n) 的计算，我们用 2 * n + 1 和 2 * n。
        
        // 递推计算下一项
        term = -term * x * x / ((2.0 * n) * (2.0 * n + 1.0));
        
        // 累加到总和
        sum += term;
        
        // 准备下一轮循环的参数
        n++; 
    }

    return sum;
}

// 函数：计算 cos(x) 的近似值
double calculate_cos(double x, double epsilon) {
    // 第一项: x^0 / 0! = 1
    double term = 1.0; 
    double sum = term;
    long long n = 1; // n 表示级数项的索引，对应于 (2n)!，从 1 开始代表下一项的幂次是 2

    // 循环条件: 当前项的绝对值大于等于 epsilon，继续计算下一项
    // 对应于 (2n)! 的指数为 2n
    while (abs(term) >= epsilon) {
        // 计算下一项的递推关系:
        // 当前项是 (-1)^(n-1) * x^(2n-2) / (2n-2)!
        // 下一项是 (-1)^n * x^(2n) / (2n)!
        // 下一项 = 当前项 * (-1) * x^2 / ((2n) * (2n-1))
        // 这里的 n 是从 1 开始的迭代次数。

        // 递推计算下一项
        term = -term * x * x / ((2.0 * n) * (2.0 * n - 1.0));
        
        // 累加到总和
        sum += term;
        
        // 准备下一轮循环的参数
        n++; 
    }

    return sum;
}


int main() {
    double x, epsilon;

    // 读取输入
    if (!(cin >> x >> epsilon)) {
        return 1; // 输入错误
    }

    // 计算 sin(x)
    double sin_approx = calculate_sin(x, epsilon);
    
    // 计算 cos(x)
    double cos_approx = calculate_cos(x, epsilon);

    // 设置输出精度为 6 位小数
    cout << fixed << setprecision(6);

    // 输出结果
    cout << sin_approx << endl;
    cout << cos_approx << endl;

    return 0;
}