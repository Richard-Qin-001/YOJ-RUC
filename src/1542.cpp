#include <iostream>
#include <string>
#include <algorithm> // 用于std::reverse

// 为__int128类型重载<<运算符
// 这个函数的作用是将__int128类型的数字转换为字符串并输出
std::ostream& operator<<(std::ostream& os, __int128 num) {
    if (num == 0) {
        return os << "0";
    }
    std::string s = "";
    bool is_negative = false;
    if (num < 0) {
        is_negative = true;
        num = -num;
    }
    // 循环取模和除法，将数字的每一位提取出来
    while (num > 0) {
        s += (num % 10) + '0';
        num /= 10;
    }
    if (is_negative) {
        s += '-';
    }
    // 因为是从个位开始提取的，所以需要反转字符串
    std::reverse(s.begin(), s.end());
    return os << s;
}

int main() {
    // 十六进制：0xFFF
    std::cout << 0xFFF << std::endl;

    // 八进制：017777
    std::cout << 017777 << std::endl;
    
    // 32位整数相加，结果会溢出，使用 long long 类型
    std::cout << 2147483647LL + 2147483647 << std::endl;
    
    // 64位整数相加，结果会溢出，需要__int128类型和自定义的打印函数
    std::cout << (__int128)9223372036854775807LL + 9223372036854775807LL << std::endl;

    return 0;
}