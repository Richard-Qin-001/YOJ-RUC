#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> input(const int&m, const int&n){
    vector<vector<int>> matrix(m, vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

int safeget(int i, int j, const vector<vector<int>>&matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    int dr[] = {-1, -1, 1, 1, 0};
    int dc[] = {-1, 1, -1, 1, 0};
    
    int sum = 0;
    
    for (int k = 0; k < 5; ++k) {
        int ni = i + dr[k];
        int nj = j + dc[k];
        if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
            sum += matrix[ni][nj];
        } 
    }
    return sum;
}

void solve(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix = input(m, n);
    int global_min = 90000;
    vector<vector<int>> result;
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            int current = safeget(i, j, matrix);
            if(global_min == current){
                vector<int> tmp = {i,j};
                result.push_back(tmp);
            }
            else if(global_min > current){
                global_min = current;
                result.clear();
                vector<int> tmp = {i, j};
                result.push_back(tmp);
               
            }
        }    
    }
    int out_len = result.size();
    cout << global_min << " " << out_len << endl;
    for (int i = out_len - 1; i >= 0; i--){
        cout << result[i][0] << " " << result[i][1] << endl;
    }

}
int main(){solve(); return 0;}