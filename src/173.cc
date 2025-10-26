#include <iostream>
#include <vector>

using namespace std;

void solve(){
    int M, n;
    cin >> M >> n;
    vector<vector<int>> matrix;
    vector<int> tmp(2);
    cin >> tmp[0] >> tmp[1];
    matrix.push_back(tmp);
    int index = 0;
    for (int i = 1; i < n; i++){
        cin >> tmp[0] >> tmp[1];
        if (tmp[0] <= matrix[index][0] && tmp[1] >= matrix[index][1]) matrix[index] = tmp;
        else if (tmp[0] <= matrix[index][0] && tmp[1] <= matrix[index][1]) matrix[index][0] = tmp[0];
        else if (tmp[0] >= matrix[index][0] && tmp[1] >= matrix[index][1]) matrix[index][1] = tmp[1];
        else if (tmp[0] >= matrix[index][0] && tmp[1] <= matrix[index][1]) continue;
        else {
            matrix.push_back(tmp);
            index++;
        }
    }
}