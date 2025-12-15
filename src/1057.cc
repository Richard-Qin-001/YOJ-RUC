#include <bits/stdc++.h>
using namespace std;

int target_score = 0;
map<tuple<int, int, int, int>, long long> memo;

long long dfs(int k, int current_score, int continuous_wrong, int abandoned){
    if(continuous_wrong >= 3){
        return (current_score == target_score) ? 1 : 0;
    }
    
    if(current_score >= 120){
        return (current_score == target_score) ? 1 : 0;
    }
    
    if(k > 18)
    {
        return (current_score == target_score) ? 1 : 0;
    }
    
    auto key = make_tuple(k, current_score, continuous_wrong, abandoned);
    if(memo.find(key) != memo.end()){
        return memo[key];
    }
    
    long long result = 0;
    result += dfs(k+1, current_score + 10, 0, abandoned);
    
    if(abandoned < 3){
        result += dfs(k+1, current_score, continuous_wrong, abandoned + 1);
    }
    
    int deduct;
    if(current_score <= 30){
        deduct = current_score;
    } else {
        deduct = (int)((double)current_score * (double)(18 - k) / 36.0);
    }
    int new_score = current_score - deduct;
    result += dfs(k+1, new_score, continuous_wrong + 1, abandoned);
    
    return memo[key] = result;
}

int main(){
    int n;
    cin >> n;
    while (n--)
    {
        cin >> target_score;
        memo.clear();
        long long solutions = dfs(1, 0, 0, 0);
        cout << solutions << (n != 0 ? " " : "");
    }
    return 0;
}