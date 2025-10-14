#include <iostream>
#include <cmath>
#include <map>

// 函数：对整数n进行质因数分解并输出结果
void primeFactorization(int n) {
    // 特殊情况：如果n小于2，直接返回
    if (n < 2) {
        return;
    }

    // 1. 处理质因数 2
    int count = 0; // 记录当前质因数的指数
    while (n % 2 == 0) {
        count++;
        n /= 2;
    }
    if (count > 0) {
        std::cout << 2 << ":" << count << std::endl;
    }

    // 2. 处理质因数 3, 5, 7, ... (只试除奇数)
    // 试除到 sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        count = 0;
        while (n % i == 0) {
            count++;
            n /= i;
        }
        if (count > 0) {
            std::cout << i << ":" << count << std::endl;
        }
    }

    // 3. 处理剩余部分
    // 如果循环结束后 n > 1，则剩下的 n 必然是一个质数
    if (n > 1) {
        std::cout << n << ":" << 1 << std::endl;
    }
}

int main() {
    int n;
    // 从标准输入读取整数 n
    if (!(std::cin >> n)) {
        return 0; // 如果读取失败，退出
    }

    // 调用质因数分解函数
    primeFactorization(n);

    return 0;
}