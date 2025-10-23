#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief 读取一个 N x M 矩阵并输出它的转置矩阵 (M x N)。
 * * 矩阵转置的规则是：原矩阵 A 中位于 (i, j) 位置的元素，在转置矩阵 A^T 中位于 (j, i) 位置。
 * * @note 矩阵元素的索引从 0 开始。
 */
void solve() {
    // N 为行数，M 为列数
    int N, M;
    
    // 1. 读取 N 和 M
    if (!(std::cin >> N >> M)) {
        // 输入读取失败或文件结束
        return;
    }

    // 2. 初始化 N x M 矩阵
    // 使用 std::vector<std::vector<int>> 来动态存储矩阵，更符合现代 C++ 习惯。
    // A[i] 代表第 i 行 (0 <= i < N)，A[i][j] 代表第 i 行第 j 列的元素 (0 <= j < M)
    std::vector<std::vector<int>> matrix_A(N, std::vector<int>(M));

    // 3. 读取矩阵 A 的所有元素
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!(std::cin >> matrix_A[i][j])) {
                // 如果在读取元素时输入提前结束，则退出
                return;
            }
        }
    }

    // 4. 计算并输出转置矩阵 A^T
    // 转置矩阵的维度是 M 行 N 列。
    
    // 外层循环遍历转置矩阵的行 (原矩阵的列)
    for (int j = 0; j < M; ++j) {
        // 内层循环遍历转置矩阵的列 (原矩阵的行)
        for (int i = 0; i < N; ++i) {
            
            // 转置矩阵 A^T 的 (j, i) 位置的元素等于原矩阵 A 的 (i, j) 位置的元素
            std::cout << matrix_A[i][j];

            // 格式要求：数据间用一个空格分隔，每行末尾没有多余空格。
            if (i < N - 1) {
                std::cout << " ";
            }
        }
        // 每一行输出结束后换行
        std::cout << "\n";
    }
}

int main() {
    // 优化输入/输出速度 (可选)
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}
