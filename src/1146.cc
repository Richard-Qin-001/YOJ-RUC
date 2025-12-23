#include <bits/stdc++.h>
using namespace std;

int L, N, M;
vector<int> x;

bool check(int mid){
    int count = 0, last = 0;
    for(int i = 0; i < N; ++i){
        if(x[i] - last < mid){
            count++;
        }
        else{
            last = x[i];
        }
    }
    if (L - last < mid)count++;
    return count <= M;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> L >> N >> M;
    x.assign(N, 0);
    for(int i = 0; i < N; ++i)cin >> x[i];
    int left = 1, right = L, ans = 0;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (check(mid)){
            ans = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }

    cout << ans << endl;
    return 0;
}