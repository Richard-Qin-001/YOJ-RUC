#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double dot_product(const vector<int>& A, const vector<int>& B){
    double production = 0.0;
    for(size_t i = 0; i < A.size(); i++) production += A[i] * B[i];
    return production;
}

double length(const vector<int>& v){
    double length = 0.0;
    for(size_t i = 0; i < v.size(); i++) length += v[i] * v[i];
    length = sqrt(length);
    return length;
}

double calculate_r(const vector<int>& A, const vector<int>& B){
    double r;
    r = (dot_product(A, B)) / (length(A) * length(B));
    return r;
}

vector<int> input(const int&n){
    vector<int> result(n);
    for(auto&a: result) cin >> a;
    return result;
}

bool compare(const vector<double>&row1, const vector<double>&row2){
    if (row1[1] != row2[1]){
        if (abs(row1[1] - row2[1]) < 1e-10) return row1[0] > row2[0];
        else return row1[1] > row2[1];
    }
    else return row1[0] > row2[0];
}  

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> A = input(8), B;
    vector<vector<double>> matrix;
    for(int i = 0; i < n; i++){
        double id;
        cin >> id;
        B = input(8);
        double r = calculate_r(A, B);
        vector<double> tmp = {id, r};
        matrix.push_back(tmp);
    }
    sort(matrix.begin(), matrix.end(), compare);
    for(int i =0; i < k; i++) cout << (int)matrix[i][0]  << " ";   
}

int main(){ios_base::sync_with_stdio(false); cin.tie(NULL);solve(); return 0;}