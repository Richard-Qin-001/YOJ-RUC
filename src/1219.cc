#include <iostream>
#include <vector>

using namespace std;

int find_index(const char& ch, const vector<char>& list){
    int index = 0;
    for(int i = 0; i < list.size(); i++) if(list[i] == ch){
        index = i;
        return index;
    }
    return index;
}

void solve(){
    vector<vector<int>> matrix(4, vector<int>(13, 0));
    vector<char> points = {'A', '2','3','4','5','6','7','8','9','T','J','Q','K'};
    vector<char> color = {'D', 'C', 'H', 'S'};
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        matrix.clear();
        matrix.assign(4, vector<int>(13, 0));
        int n;
        cin >> n;
        for(int j = 0; j < n; j++){
            char ch1, ch2;
            cin >> ch1 >> ch2;
            int row = find_index(ch1, color), col = find_index(ch2, points);
            matrix[row][col] ++;
        }
        int count = 0;
        for(int i = 0; i < 4; i++) for(int j = 0; j < 13; j++) if(matrix[i][j] == 0) count++;
        cout << count << endl;
    }
}
    
int main(){solve(); return 0;}