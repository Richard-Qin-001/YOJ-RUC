#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> L(N), Y(N);
    for(int i = 0; i < N; ++i)cin >> L[i];
    for(int i = 0; i < N; ++i)cin >> Y[i];
    ranges::sort(L);
    ranges::sort(Y);
    int result = 0, i = 0, j = 0;
    while(i < N && j < N){
        if(Y[j] > L[i]){
            result++;
            i++;
            j++;
        }
        else j++;
    }
    cout << result << endl;
    return 0;
}