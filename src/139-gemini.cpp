#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> times(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> times[i];
    }
    
    // 找出最长时间和最短时间
    int max_time = *std::max_element(times.begin(), times.end());
    int min_time = *std::min_element(times.begin(), times.end());
    
    // 计算总时间
    long long total_time = std::accumulate(times.begin(), times.end(), 0LL);
    
    // 计算平均时间并四舍五入
    double avg_time_double = static_cast<double>(total_time) / n;
    int avg_time = static_cast<int>(std::round(avg_time_double));
    
    std::cout << max_time << " " << min_time << " " << avg_time << std::endl;
    
    return 0;
}