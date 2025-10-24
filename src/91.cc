#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void sample(vector<vector<double>>& db, const int n, const int&index){
    vector<double> tmp(18, 0);
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        if (k >= 0 && k <= 15) tmp[0]++;
        else if (k >= 16 && k <= 31) tmp[1]++;
        else if (k >= 32 && k <= 47) tmp[2]++;
        else if (k >= 48 && k <= 63) tmp[3]++;
        else if (k >= 64 && k <= 79) tmp[4]++;
        else if (k >= 80 && k <= 95) tmp[5]++;
        else if (k >= 96 && k <= 111) tmp[6]++;
        else if (k >= 112 && k <= 127) tmp[7]++;
        else if (k >= 128 && k <= 143) tmp[8]++;
        else if (k >= 144 && k <= 159) tmp[9]++;
        else if (k >= 160 && k <= 175) tmp[10]++;
        else if (k >= 176 && k <= 191) tmp[11]++;
        else if (k >= 192 && k <= 207) tmp[12]++;
        else if (k >= 208 && k <= 223) tmp[13]++;
        else if (k >= 224 && k <= 239) tmp[14]++;
        else if (k >= 240 && k <= 255) tmp[15]++;
    }
    tmp[17] = index;
    db.push_back(tmp);
}

void calculate(vector<vector<double>>& db){
    size_t n = db.size();
    for(int i = 1; i < n; i++){
        double sum = 0;
        for (int j = 0; j < 16; j++){
            sum += pow(db[i][j] - db[0][j], 2);
        }
        db[i][16] = sqrt(sum);
    }
}

bool compare(const vector<double>& row1, const vector<double>& row2){
    if (row1[16] != row2[16]) return row1[16] < row2[16];
    else return row1[17] < row2[17];
}

void solve(){
    vector<vector<double>> db;
    int n0;
    cin >> n0;
    sample(db, n0, 0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        int p;
        cin >> p;
        sample(db, p, i);
    }
    calculate(db);
    sort(db.begin()+1, db.end(), compare);
    for(int i = 1; i <= k; i++) {
        if (i != k) cout << (int)db[i][17] << " ";
        else cout << (int)db[i][17] << endl;
    }
}
int main(){solve(); return 0;}