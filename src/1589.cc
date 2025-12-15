#include <bits/stdc++.h>

int m, n;
std::vector<std::vector<int>> matrix;
std::vector<std::vector<int>> memo;
std::vector<std::vector<int>> status;

int dx[5] = {0, 0, 0, -1, 1}, dy[5] = {0, -1, 1, 0, 0};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> m >> n;
    matrix.assign(n, std::vector<int>(m, 0)), memo.assign(n, std::vector<int>(m, 0)), status.assign(n, std::vector<int>(m, 0));
    std::vector<std::pair<int, int>> solutions;
    for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)std::cin >> matrix[i][j];
    int global_max = 0, current_max = 0;
    std::vector<std::pair<int, int>> stack;
    stack.reserve(m*n);
    for(int i = 0; i < n; i++)for(int j = 0; j < m; j++){
            int start_x = i, start_y = j, current_x = i, current_y = j, loop_x = -1, loop_y = -1;
            stack.clear();
            while (true)
            {
                if (current_x < 0 || current_x >= n || current_y < 0 || current_y >= m)
                    break;
                if (status[current_x][current_y] == 2)
                    break;
                if (status[current_x][current_y] == 1)
                {
                    loop_x = current_x, loop_y = current_y;
                    break;
                }
                status[current_x][current_y] = 1;
                stack.push_back({current_x, current_y});
                int tmp1, tmp2;
                tmp1 = current_x + dx[matrix[current_x][current_y]];
                tmp2 = current_y + dy[matrix[current_x][current_y]];
                current_x = tmp1;
                current_y = tmp2;
            }
        if(loop_x != -1 && loop_y != -1){
            std::vector<std::pair<int, int>> loops = {{loop_x, loop_y}};
            int loop_len = 1;
            int tmp1, tmp2;
            tmp1 = loop_x + dx[matrix[loop_x][loop_y]];
            tmp2 = loop_y + dy[matrix[loop_x][loop_y]];
            current_x = tmp1;
            current_y = tmp2;
            while (current_x != loop_x || current_y != loop_y){
                loop_len++;
                loops.push_back({current_x, current_y});
                int tmp1, tmp2;
                tmp1 = current_x + dx[matrix[current_x][current_y]];
                tmp2 = current_y + dy[matrix[current_x][current_y]];
                current_x = tmp1;
                current_y = tmp2;
                }
            for(auto&p:loops){
                memo[p.first][p.second] = loop_len;
                status[p.first][p.second] = 2;
            }
            int loop_start_index = -1;
            for (int k = 0; k < stack.size(); ++k) {
                if (stack[k].first == loop_x && stack[k].second == loop_y) {
                    loop_start_index = k;
                    break;
                }
            }

            if (loop_start_index != -1) {
                stack.erase(stack.begin() + loop_start_index, stack.end());
            }
            loop_x = -1, loop_y = -1;
        }
        if(current_x < 0 || current_x >= n || current_y < 0 || current_y >= m)current_max = 0; 
        else current_max = memo[current_x][current_y];
        int len = stack.size();
        for(int p = len - 1; p >= 0; p--){
            current_max++;
            memo[stack[p].first][stack[p].second] = current_max;
            status[stack[p].first][stack[p].second] = 2;
        }
        if(current_max > global_max){
            global_max = current_max;
            solutions.clear();
            solutions.push_back({start_y, start_x});
        }
        else if(current_max == global_max)solutions.push_back({start_y, start_x});
    }
    std::ranges::sort(solutions, [](const std::pair<int ,int>&p, const std::pair<int, int>&q){
        if(p.first != q.first)return p.first < q.first;
        return p.second < q.second;
    });
    for(const auto&p:solutions) std::cout << p.first << " " << p.second << "\n";
    return 0;
}

//变量赋值千万要注意两个变量之间的相互影响关系
/*
这样写是对的:
int tmp1, tmp2;
tmp1 = current_x + dx[matrix[current_x][current_y]];
tmp2 = current_y + dy[matrix[current_x][current_y]];
current_x = tmp1;
current_y = tmp2;

这样写是错的:
current_x = current_x + dx[matrix[current_x][current_y]], current_y = current_y + dy[matrix[current_x][current_y]];

这里 current_x 和 current_y 是相关的，代码执行的顺序是从左到右，在对 current_x 赋值之后， current_x的值已经改变了，这时候再对 current_y 赋值，
就不是用原来的 current_x 索引去访问数表了，得出的 current_y 自然不是想要的值。

*/