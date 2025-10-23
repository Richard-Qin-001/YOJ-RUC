#include <iostream>
#include <vector>

using namespace std;

int MOD = 7;

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
    int A, B, n;
    cin >> A >> B >> n;
    if (n == 1 || n == 2){
        cout << 1 % 7;
        return;
    }
    else{
        vector<vector<long long>> base = {
            {A, B},
            {1, 0},
        };
        vector<vector<long long>> u1 = {
            {1},
            {1},
        };
        vector<vector<long long>> tmp = matrix_power(base, n-2);
        vector<vector<long long>> uk = matrix_multiply(tmp, u1) ;
        cout << uk[0][0];
    }
}
int main(){solve(); return 0;}