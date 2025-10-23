#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

/**
 * 检查当前假设 (who_shot_it) 下，八位大将有多少人猜对了。
 * * @param who_shot_it 假设射中鹿的人（'A' 到 'H'）
 * @return 猜对的人数
 */
int count_correct_guesses(char who_shot_it) {
    int correct_count = 0;

    // A说：“或者是H将军射中的，或者是F将军射中的。” (H || F)
    // A正确：当 who_shot_it 是 'H' 或 'F'
    if (who_shot_it == 'H' || who_shot_it == 'F') {
        correct_count++;
    }

    // B说：“鹿肯定是我射中的啦。” (B)
    // B正确：当 who_shot_it 是 'B'
    if (who_shot_it == 'B') {
        correct_count++;
    }

    // C说：“我可以断定是G将军射中的。” (G)
    // C正确：当 who_shot_it 是 'G'
    if (who_shot_it == 'G') {
        correct_count++;
    }

    // D说：“怎么说也不可能是B将军射中的！” (!B)
    // D正确：当 who_shot_it 不是 'B'
    if (who_shot_it != 'B') {
        correct_count++;
    }

    // E说：“A将军猜错了。” (!(H || F))
    // E正确：当 A 错误 (who_shot_it 既不是 'H' 也不是 'F')
    if (!(who_shot_it == 'H' || who_shot_it == 'F')) {
        correct_count++;
    }

    // F说：“不会是我射中的，也不是H将军射中的。” (!F && !H)
    // F正确：当 who_shot_it 既不是 'F' 也不是 'H'
    if (who_shot_it != 'F' && who_shot_it != 'H') {
        correct_count++;
    }

    // G说：“绝对不是C将军射中的。” (!C)
    // G正确：当 who_shot_it 不是 'C'
    if (who_shot_it != 'C') {
        correct_count++;
    }

    // H说：“我同意A将军的观点。” (A的言论，即 H || F)
    // H正确：当 who_shot_it 是 'H' 或 'F'
    if (who_shot_it == 'H' || who_shot_it == 'F') {
        correct_count++;
    }

    return correct_count;
}

int main() {
    // 设置 I/O 加速
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // 读取猜对的人数 n
    if (!(cin >> n)) {
        return 0; // 输入失败则退出
    }

    // 存储所有可能的射鹿人，他们导出的正确人数 n 与输入匹配
    vector<char> possible_shooters;
    
    // 枚举每一位大将射中鹿的可能性：'A' 到 'H'
    for (char shooter = 'A'; shooter <= 'H'; ++shooter) {
        // 计算在 shooter 射中鹿的假设下，猜对的人数
        int correct = count_correct_guesses(shooter);

        // 如果计算出的正确人数与输入的 n 匹配，则将 shooter 加入候选列表
        if (correct == n) {
            possible_shooters.push_back(shooter);
        }
    }

    // 根据结果输出
    if (possible_shooters.size() == 1) {
        // 唯一解
        cout << possible_shooters[0] << endl;
    } else {
        // 无解或多解
        cout << "DONTKNOW" << endl;
    }

    return 0;
}