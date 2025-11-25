#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> class_seat;
int max_students = 0;

// void DFS(){

// }

void solve(){
    int n, m;
    cin >> n >> m;
    class_seat.assign(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i)for(int j = 0; j < m; ++j)cin >> class_seat[i][j];

}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}