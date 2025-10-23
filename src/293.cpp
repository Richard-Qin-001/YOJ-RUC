#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int matrix[n][m];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    
    int total = 0;
    
    if (n == 1) {
        for (int j = 0; j < m; j++) {
            total += matrix[0][j];
        }
    } else if (m == 1) {
        for (int i = 0; i < n; i++) {
            total += matrix[i][0];
        }
    } else {
        // 计算第一行和最后一行的所有元素
        for (int j = 0; j < m; j++) {
            total += matrix[0][j];        // 第一行
            total += matrix[n-1][j];      // 最后一行
        }
        
        // 计算第一列和最后一列的中间部分（排除首尾元素）
        for (int i = 1; i < n-1; i++) {
            total += matrix[i][0];        // 第一列
            total += matrix[i][m-1];      // 最后一列
        }
    }
    
    cout << total << endl;
    
    return 0;
}