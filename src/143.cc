#include <bits/stdc++.h>
using namespace std;

int N, sum;
vector<int> solution, coeffs;
vector<bool> used;
bool found = false;

void calculate_coeffs(int N) {
    vector<int> row(N);
    row[0] = 1;

    for (int i = 1; i < N; i++) {
        for (int j = i; j >= 1; j--) {
            row[j] = row[j] + row[j-1];
        }
    }
    coeffs.assign(row.begin(), row.end());
}

void DFS(int k, int current_sum){
    if(found) return;
    if (k == N){
        if(current_sum == sum)found = true;
        return;
    }
    for(int i = 1; i <= N; i++)if(!used[i]){
        int new_sum = current_sum + i * coeffs[k];
        if (new_sum > sum)break; 
        solution[k] = i;
        used[i] = true;
        DFS(k+1, new_sum);
        if(found) return;
        used[i] = false;
    }
}

void solve(){
    cin >> N >> sum;
    solution.assign(N, 0), coeffs.assign(N, 0), used.assign(N+1, false);
    calculate_coeffs(N);
    DFS(0, 0);
    for(int i = 0; i < N; i++) cout << solution[i] << " ";
    cout << endl;
}

int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}