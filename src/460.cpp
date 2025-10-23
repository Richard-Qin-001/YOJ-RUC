# include <iostream>
# include <vector>
# include <algorithm>


using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    long long sum = 0;
    for (int i = 0 ; i < n; i++){
        cin >> v[i];
        sum += v[i];
    }
    long long matrix[4][n+1];
    long long p = 0, q = sum;
    long long current_difference = 0;
    long long global_difference = abs(sum);
    for (int i = 1; i <= n+1; i++){
        int col_idx = i - 1;
        if (i == 1) {
            p = 0;
            q = sum;
        }
        else if (i == n+1) {
            p = sum;
            q = 0;
        }
        else{
            p += v[i-2];
            q -= v[i-2];
        }
        current_difference = abs(p - q);
        matrix[0][col_idx] = i; 
        matrix[1][col_idx] = p; 
        matrix[2][col_idx] = q; 
        matrix[3][col_idx] = current_difference;
        global_difference = min(current_difference, global_difference); 
    }
    for (int i = 1; i <= n+1; i++){
        if (matrix[3][i-1] == global_difference){
            if (matrix[1][i-1] - matrix[2][i-1] >= 0){
                cout << matrix[1][i-1] << " " << matrix[2][i-1] << endl;
                return 0;
            }
        }
    }
    for (int i = 1; i <= n+1; i++){
        if (matrix[3][i-1] == global_difference){
                cout << matrix[1][i-1] << " " << matrix[2][i-1] << endl;
                return 0;
        }
    }
    return 0;

}

// 待优化