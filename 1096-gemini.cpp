#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm> // 用于 std::max

// 读入：
// 1. DNA 序列 (string)
// 2. 连续碱基长度 k (int)
// 输出：
// 出现次数最多的 k-mer 的出现次数 (int)

int main() {
    // 提高输入输出速度
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // 读取 DNA 序列
    std::string dna_sequence;
    std::cin >> dna_sequence;

    // 读取连续碱基长度 k
    int k;
    std::cin >> k;

    // 获取 DNA 序列的长度 N
    int N = dna_sequence.length();

    // 如果序列长度 N 小于 k，则无法形成任何 k-mer
    if (N < k) {
        std::cout << 0 << "\n";
        return 0;
    }

    // 使用 unordered_map (哈希表) 来存储每个 k-mer 及其出现次数。
    // 键是 k-mer 字符串，值是出现次数。
    std::unordered_map<std::string, int> kmer_counts;

    // 存储出现最多的 k-mer 的出现次数
    int max_count = 0;

    // 使用滑动窗口遍历序列。
    // 窗口的起始索引 i 从 0 开始，到 N - k 结束。
    // 这样可以确保子串 dna_sequence.substr(i, k) 是一个合法的 k-mer。
    for (int i = 0; i <= N - k; ++i) {
        // 1. 提取当前窗口的 k-mer 子串
        // substr(起始位置, 长度)
        std::string kmer = dna_sequence.substr(i, k);

        // 2. 统计 k-mer 的出现次数并更新
        // unordered_map::operator[] 会自动处理键不存在的情况 (初始化为 0)
        kmer_counts[kmer]++;

        // 3. 更新最大出现次数
        // kmer_counts[kmer] 已经是当前 k-mer 的最新次数
        if (kmer_counts[kmer] > max_count) {
            max_count = kmer_counts[kmer];
        }
        
        // 也可以使用标准库函数 std::max (如果不需要频繁更新，可放在循环外)
        // max_count = std::max(max_count, kmer_counts[kmer]);
    }

    // 输出最终结果
    std::cout << max_count << "\n";

    return 0;
}