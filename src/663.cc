#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<vector<int>> input_matrix(int N){
    vector<vector<int>> matrix(N, vector<int> (N));
    for(auto&row:matrix)for(auto&column:row)cin>> column;
    return matrix;
}

void solve(){
    int N;
    cin >> N;
    vector<vector<int>> matrix = input_matrix(N);
    ll min = matrix[0][0];
    for(int i = 0; i < N; i++){
        int m1 = matrix[i][i];
        int m2 = matrix[i][N-i-1];
        if(m1 < min) min = m1;
        if(m2 < min) min = m2;
    }
    cout << min << endl;
}
int main(){solve(); return 0;}