#include <bits/stdc++.h>
using namespace std;
int n, m;
int count1 = 0, count2 = 0;

void DFS(int mask, int current_a, int current_b, int current_c, int target){
    if(mask == ((1 << m) -1))
    {
        if (current_c == 0)
            return;
        int k = n - current_a;
        if (k > 0 && current_b % current_c == 0 && current_b / current_c == k)
            count1++;
        if (k >= 0 && current_b % current_c == k)
            count2++;
        return;
    }

    if (target == 1 && current_a > 0)
        DFS(mask, current_a, 0, 0, 2);
    if (target == 2 && current_b > 0)
        DFS(mask, current_a, current_b, 0, 3);

    for (int d = 1; d <= m; d++)
        {
            if (!(mask & (1 << (d - 1))))
            {
                int new_mask = mask | (1 << (d - 1));
                if (target == 1)
                {
                    int next_a = current_a * 10 + d;
                    if(next_a <= n)
                    DFS(new_mask, next_a, current_b, current_c, 1);
                }
                else if (target == 2)
                {
                    int next_b = current_b * 10 + d;
                    if (next_b < n * 100000)
                        DFS(new_mask, current_a, next_b, current_c, 2);
                }
                else if (target == 3)
                {
                    int next_c = current_c * 10 + d;
                    DFS(new_mask, current_a, current_b, next_c, 3);
                }
            }
        }
    }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int initial_mask = (1 << (i - 1));
        DFS(initial_mask, i, 0, 0, 1);
    }
    cout << count1 << " " << count2 << endl;
    return 0;
}