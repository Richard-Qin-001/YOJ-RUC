#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s;
int m;
long long memo[20][20];

// 辅助函数，将子字符串转换为长整型
long long string_to_long(int start, int end) {
    long long res = 0;
    for (int i = start; i < end; ++i) {
        res = res * 10 + (s[i] - '0');
    }
    return res;
}

// 递归函数，求解最大值
long long solve(int index, int pluses_left) {
    // 记忆化
    if (memo[index][pluses_left] != -1) {
        return memo[index][pluses_left];
    }
    
    // 基准情况：没有加号需要插入
    if (pluses_left == 0) {
        return string_to_long(index, s.length());
    }

    long long max_val = 0;
    
    // 遍历所有可能的加号位置
    // 加号位置从 index+1 开始，到 s.length() - pluses_left 结束
    // 确保加号后面至少还有 pluses_left 个字符
    for (int i = index + 1; i <= s.length() - pluses_left; ++i) {
        long long current_val = string_to_long(index, i);
        long long next_max_val = solve(i, pluses_left - 1);
        max_val = max(max_val, current_val + next_max_val);
    }
    
    return memo[index][pluses_left] = max_val;
}

int main() {
    cin >> m >> s;
    
    // 初始化记忆化数组
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            memo[i][j] = -1;
        }
    }
    
    cout << solve(0, m) << endl;
    
    return 0;
}
