#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> matrix(n ,vector<int>(n));
    for(auto&r:matrix)for(auto&c:r)cin >> c;
    int k;
    cin >> k;
    while (k--)
    {
        int target;
        cin >> target;
        int r = 0, c = n - 1;
        while (r < n && c >= 0)
        {
            if(matrix[r][c] == target){
                cout << r << " " << c << endl;
                goto end_loop;
            }
            else if(matrix[r][c] > target)
                c--;
            else r++;    
        }
        cout << -1 << endl;
        end_loop:
            ;
    }
    return 0;
}