#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> an(N);
    for(auto&ai:an)cin >> ai;
    int sum = 0;
    int result = 0;
    for(int i = 0; i < N; ++i){
        sum += an[i];
        if(sum > M){
            sum = an[i];
            result++;
        }
    }
    if(sum > 0)result++;
    cout << result << endl;
}