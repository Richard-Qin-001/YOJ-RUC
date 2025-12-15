#include <bits/stdc++.h>
using namespace std;

struct Counterweight
{
    int weight;
    int number;
};

int n;
vector<Counterweight> counterweights;
int cnt = 0;
map<pair<int, int>, long long> memo;
vector<pair<int, int>> solutions;
int target = 0;

void dfs(int idx, int cnw){
    if (idx == n)
    {
        if (cnw == target)
            cnt++;
        return;
    }
    pair<int, int> state = {idx, cnw};
    if (memo.find(state) != memo.end())
    {
        cnt += memo[state];
        return;
    }
    int before = cnt;
    const int w = counterweights[idx].weight;
    const int num = counterweights[idx].number;
    for(int i = 0; i <= num; ++i)
    {
        int nxtwt = cnw + i * w;
        if(nxtwt > target)return;
        dfs(idx+1, nxtwt);
    }
    memo[state] = cnt - before;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> n >> m;
    counterweights.assign(n, {0, 0});
    solutions.reserve(m);
    for(int i = 0; i < n; ++i)cin >> counterweights[i].weight;
    for(int i = 0; i < n; ++i)cin >> counterweights[i].number;
    for(int i = 0; i < m; ++i){
        cin >> target;
        memo.clear();
        cnt = 0;
        dfs(0, 0);
        solutions.push_back({target, cnt});
    }
    sort(solutions.begin(), solutions.end(), [](const pair<int, int>&a, const pair<int, int>&b){
        if(a.second != b.second)return a.second > b.second;
        return a.first < b.first;
    });
    for(int i = 0; i < m; ++i){
        cout << solutions[i].first << ":" << solutions[i].second << "\n";
    }
    return 0;
}