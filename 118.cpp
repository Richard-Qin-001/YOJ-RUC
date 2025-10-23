#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 10000;

vector<vector<long long>> matrix_multiply(vector<vector<long long>>& m_1, vector<vector<long long>>& m_2){
    size_t n = m_1.size();
    size_t m = m_2.size();
    size_t p = m_2[0].size();
    vector<vector<long long>> matrix(n, vector<long long>(p));
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < p; j++){
            long long combination = 0;
            for (size_t k = 0; k < m; k++){
                combination = (combination + (m_1[i][k] * m_2[k][j])%MOD) % MOD;
            }
            matrix[i][j] = combination;
        }
    }
    return matrix;
}

vector<vector<long long>> matrix_power(vector<vector<long long>>& base, long long power){
    size_t size = base.size();
    vector<vector<long long>> result(size, vector<long long>(size));
    for (size_t i = 0; i < size; i++) result[i][i] = 1;
    while (power > 0){
        if (power & 1){
            result = matrix_multiply(result, base);

        }
        base = matrix_multiply(base, base);
        power >>= 1;
    }
    return result;
}

void solve(){
    long n;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return;
    }
    else if (n == 1){
        cout << 1;
        return;
    }
    vector<vector<long long>> base = {{1, 1},{1, 0}};
    vector<vector<long long>> result;
    result = matrix_power(base, n-1);     
    long long fn = result[0][0];
    cout << fn << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    solve();
    return 0;
}