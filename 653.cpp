# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main(){
    int n = 0;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i <n; i++){
        cin >> v[i];
    }
    int current_max = v[0];
    int global_max = v[0];
    for (int i = 1; i < n; i++) {
        current_max = max(v[i], current_max + v[i]);
        global_max = max(global_max, current_max);
    }
    cout << global_max << endl;
    return 0;
}
// #include <iostream>
// #include <vector>
// #include <algorithm> // 包含 std::max 函数

// int main() {
//     int n;
//     // 读取序列的长度 n
//     std::cin >> n;

//     // 创建一个向量来存储序列中的整数
//     std::vector<int> a(n);
//     for (int i = 0; i < n; ++i) {
//         std::cin >> a[i];
//     }

//     // 如果序列为空，直接返回0或根据题目要求处理
//     if (n == 0) {
//         std::cout << 0 << std::endl;
//         return 0;
//     }

//     // current_max: 以当前元素结尾的最大连续和
//     // global_max: 整个序列的最大连续和
//     int current_max = a[0];
//     int global_max = a[0];

//     // 从第二个元素开始遍历
//     for (int i = 1; i < n; ++i) {
//         // 比较：是新开一个子序列（从当前元素a[i]开始）
//         // 还是在之前的子序列上继续累加
//         current_max = std::max(a[i], current_max + a[i]);
        
//         // 更新全局最大值
//         global_max = std::max(global_max, current_max);
//     }

//     // 输出结果
//     std::cout << global_max << std::endl;

//     return 0;
// }