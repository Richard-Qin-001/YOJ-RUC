#include <bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin >> n;
    vector<double> p0(n);
    for(int i = 0; i < n; ++i)cin>>p0[i];
    vector<vector<double>> matrix;
    vector<double>rowi(n + 1);
    vector<double>pi(n);
    double rin;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j){
            cin >> pi[j];
            rowi[j] = (pi[j] - p0[j]) * 2.0;
        }
        rin = 0.0;
        for(int j = 0; j < n; ++j)
        {
            rin += (pi[j] + p0[j]) * (pi[j] - p0[j]);
        }
        rowi[n] = rin;
        matrix.emplace_back(rowi);
    }

    for(int i = 0; i < n; ++i)
    {
        int max_r = i;
        for(int j = i + 1; j < n; ++j){
            if(abs(matrix[j][i]) > abs(matrix[max_r][i])){
                max_r = j;
            }
        }
        swap(matrix[max_r], matrix[i]);
        double pivot = matrix[i][i];

        for (int j = i; j < n + 1; ++j)
        {
            matrix[i][j] /= pivot;
        }

        for(int j = 0; j < n; ++j)
        {
            if(j != i){
                double factor = matrix[j][i];
                for(int k = i; k < n + 1; ++k)
                {
                    matrix[j][k] -= factor * matrix[i][k];
                }
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        printf("%.3f%c", matrix[i][n], (i == n - 1 ? '\n' : ' '));
    }

    return 0;
}