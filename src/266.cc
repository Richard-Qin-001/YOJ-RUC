#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> rot(const vector<vector<int>>&matrix, int degree){
    vector<vector<int>> result;
    degree %= 360;
    if(degree < 0) degree = 360 + degree;
    if(degree == 0) return matrix;
    if(degree == 90){
        result.assign(m, vector<int>(n, 0));
        for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)result[j][n-1-i] = matrix[i][j];
        return result;
    }
    if(degree == 180){
        result.assign(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)result[n-1-i][m-1-j] = matrix[i][j];
        return result;
    }
    if(degree == 270){
        result.assign(m, vector<int>(n, 0));
        for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)result[m-1-j][i] = matrix[i][j];
        return result;
    }
    return result;
}

void solve(){
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(auto&r:matrix)for(auto&c:r)cin>>c;
    int degree;
    cin >> degree;
    vector<vector<int>> result = rot(matrix, degree);
    for(auto&r:result){
        for(auto&c:r)cout << c << " ";
        cout << endl;
    }
}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}