#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    double height = 0.0, max_height = 0.0, min_height = DBL_MAX;
    ld total = 0.0;
    for(auto&r:matrix)for(auto&c:r){
        cin >> height;
        total += height;
        min_height = min(min_height, height);
        max_height = max(max_height, height);
    }
    double mean_height = total / ((double)n*n);
    cout << fixed << setprecision(3) << max_height << " " << min_height << " " << setprecision(2) << mean_height << endl;
    return 0;

}