#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> acts(n, vector<int>(2));
    for(int i = 0; i < n; ++i)
        cin >> acts[i][0] >> acts[i][1];
    sort(acts.begin(), acts.end(), [](const vector<int>&a, const vector<int>&b){
        if(a[1] != b[1]) return a[1] < b[1];
        return a[0] > b[0];
    });
    int max_acts = 1;
    int last_finish_time = acts[0][1];
    for(int i = 1; i < n; i++){
        if(acts[i][0] >= last_finish_time){
            max_acts++;
            last_finish_time = acts[i][1];
        }
    }
    cout << max_acts << endl;
    return 0;
}