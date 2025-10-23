#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    // 禁用 C++ 标准流与 C 标准流同步，以提高输入输出速度
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // 使用 unordered_set 存储书名，实现O(1)平均时间的查找和插入
    std::unordered_set<std::string> library;
    
    std::string operation, bookName;

    for (int i = 0; i < n; ++i) {
        std::cin >> operation >> bookName;

        if (operation == "add") {
            // 向集合中添加书名
            library.insert(bookName);
        } else if (operation == "find") {
            // 在集合中查找书名
            if (library.count(bookName)) {
                std::cout << "yes\n";
            } else {
                std::cout << "no\n";
            }
        }
    }

    return 0;
}