#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits> // 用于初始化众数值

using namespace std;

int main() {
    // 禁用同步，加速IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // 读入序列长度
    if (!(cin >> n) || n <= 0) {
        // 如果输入无效或长度小于等于0
        cout << "NO" << endl;
        return 0;
    }

    // 使用unordered_map进行频率统计：键是数字，值是频率
    unordered_map<int, int> counts;
    int num;
    for (int i = 0; i < n; ++i) {
        if (cin >> num) {
            counts[num]++;
        }
    }

    // ---------------------- 查找众数 ----------------------
    
    // max_freq 记录当前找到的最高频率，初始化为0
    int max_freq = 0; 
    
    // mode_value 记录当前找到的众数值
    // 初始化为 int 的最小值，确保任何读入的数字都会在第一次比较时正确赋值
    int mode_value = numeric_limits<int>::min(); 
    
    // 遍历哈希表，查找众数
    for (const auto& pair : counts) {
        int current_num = pair.first;
        int current_freq = pair.second;

        // 1. 如果找到更高的频率
        if (current_freq > max_freq) {
            max_freq = current_freq;
            mode_value = current_num;
        } 
        // 2. 如果频率相同，根据题目要求，选择值更大的众数
        else if (current_freq == max_freq) {
            if (current_num > mode_value) {
                mode_value = current_num;
            }
        }
    }

    // ---------------------- 输出结果 ----------------------
    
    // 众数的定义：频率大于1，且频率最高
    if (max_freq > 1) {
        // 输出格式：m n (众数值 出现次数)
        cout << mode_value << " " << max_freq << endl;
    } else {
        // 序列中没有频率大于1的数，即没有众数
        cout << "NO" << endl;
    }

    return 0;
}