#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> y(m+1, 0);
    vector<vector<int>> x(m+1, vector<int>(2, 0));
    int li, word;
    for(int i = 0; i < n; ++i){
        cin >> li;
        for(int j = 0; j < li; ++j){
            cin >> word;
            y[word]++;
            if(x[word][1]==0){
                x[word][0]++;
                x[word][1]++;
            }
        }
        for(int j = 1; j <= m; ++j)x[j][1] = 0;
    }
    for(int i = 1; i <= m; ++i){
        cout << x[i][0] << " " << y[i] << "\n";
    }
    return 0;
}