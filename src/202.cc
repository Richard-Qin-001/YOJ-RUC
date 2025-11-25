#include <bits/stdc++.h>
using namespace std;
bool check(int p, int b);
void solve();
int main();

vector<vector<int>> favorite;
vector<vector<int>> solutions;
vector<int> solution;
vector<bool> books;
int total_solutions = 0;
int n;

bool check(int p, int b){
    return favorite[p][b-1] == 1 && books[b-1];
}

void DFS(int index){
    if (index==n){
        total_solutions++;
        solutions.push_back(solution);
        return;
    }
    for(int i = 1; i <= n; i++){
        if(check(index, i)){
            solution[index] = i;
            books[i-1] = false;
            DFS(index+1);
            books[i-1] = true;
        }
    }
}

void solve(void){
    cin >> n;
    favorite.assign(n, vector<int>(n, 0));
    solution.assign(n, 0);
    books.assign(n, true);
    for(int i = 0; i < n; i++)for(int j = 0; j < n; j++){
        char cbook;
        cin >> cbook;
        favorite[i][j] = cbook - '0';
    }
    DFS(0);
    if (total_solutions == 0) cout << "NO" << endl;
    else {
        cout << total_solutions << endl;
        for(int i = 0; i < total_solutions; i++){
            for(int j = 0; j < n; j++)cout << "B" << solutions[i][j];
            cout << endl;
        }
    }
}

int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}