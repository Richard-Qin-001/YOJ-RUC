#include <bits/stdc++.h>
using namespace std;

int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int calculate_cost(int n){
    int result = 0;
    string str = to_string(n);
    int len = str.length();
    for(int i = 0; i < len; ++i){
        result += cost[str[i] - '0'];
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    n -= 4;
    int total_solutions = 0;
    for(int i = 0; i < 1000; ++i){
        int a = calculate_cost(i);
        if(a >= n)continue;
        for(int j = 0; j < 1000; ++j){
            if(i == j)continue;
            int b = calculate_cost(j);
            if(b >= n)continue;
            int C = i + j;
            int c = calculate_cost(C);
            if(a + b + c == n)total_solutions++;
        }
        if(a * 2 > n)continue;
        int C = 2 * i;
        int c = calculate_cost(C);
        if(a * 2 + c == n)total_solutions++;
    }
    cout << total_solutions << endl;
}