#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> maxs(n);
    for(int i = 0; i < n; i++){
        vector<int> input(m);
        for(auto&c:input) cin >> c;
        sort(input.begin(), input.end(),
        [](int a, int b){
            return a > b;
        }    
    );
    maxs[i] = input[0];  
    }
    sort(maxs.begin(), maxs.end());
    cout << maxs[0];
}
int main(){solve(); return 0;}