#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<string, int> board_count;
    for(int i = 0; i < n; i++){
        string board = "";
        for(int j = 0; j < 8; j++){
            string row;
            cin >> row;
            board += row;
        }
        cout << ++board_count[board] << "\n";
    }
    return 0;
}