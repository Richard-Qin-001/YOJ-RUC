#include <iostream>
#include <vector>

using namespace std;

int getWhite(const vector<vector<int>>&board, const int&i, const int&j){
    int result = 0;
    int rows = board.size(), cols = board[0].size();
    result += (i-1 >=0 && board[i-1][j]==1) ? 1 : 0;
    result += (j-1 >=0 && board[i][j-1]==1) ? 1 : 0;
    result += (i+1 <rows && board[i+1][j]==1) ? 1 : 0;
    result += (j+1 <cols && board[i][j+1]==1) ? 1 : 0;
    return result;
}

void transform(vector<vector<int>>&board){
    vector<vector<int>> new_board = board;
    int rows = new_board.size(), cols = new_board[0].size();
    for(int i = 0; i < rows; i++)for(int j = 0; j < cols; j++){
        int white_num = getWhite(board, i, j);
        if(board[i][j]==1){
            if(white_num < 2) new_board[i][j] = 0;
            else if(white_num == 2 || white_num == 3) new_board[i][j] = 1;
            else if(white_num == 4) new_board[i][j] = 0;
        }
        else if(white_num==3)new_board[i][j] = 1;  
    }
    board = new_board;
}

void solve(){
    int rows, cols, steps;
    cin >> rows >> cols >> steps;
    vector<vector<int>> board(rows, vector<int>(cols, 0));
    for(auto&row:board)for(auto&col:row)cin >> col;
    for(int i = 0; i < steps; ++i)transform(board);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
        cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}