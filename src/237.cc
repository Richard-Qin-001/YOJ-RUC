#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> stones(N);
    for(auto&s:stones)cin >> s;
    int total = accumulate(stones.begin(), stones.end(), 0);
    int avg = total / N;

    vector<int> diff(N);
    for(int i = 0; i < N; i++)diff[i] = stones[i] - avg;
    int global_min = 1e9, current_min = 0;
    for(int i = 0; i < N; ++i){
        vector<int> prefix(N);
        prefix[0] = diff[i];
        for(int j = 1; j < N; j++)prefix[j] = prefix[j - 1] + diff[(i + j) % N];
        current_min = 0;
        for(int j = 0; j < N - 1; j++)current_min += abs(prefix[j]);
        global_min = min(global_min, current_min);
    }
    cout << global_min << endl;
    return 0;
}