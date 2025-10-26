#include <iostream>
#include <vector>
// 布尔数组
using namespace std;

void remove(vector<bool>&tree_removed, const int&l, const int&r){
    for(int i = l; i <= r; i++) tree_removed[i] = true;
}

void solve(){
    int L, M;
    cin >> L >> M;
    vector<bool> tree_removed(L+1, false);
    for(int i = 0; i < M; i++){
        int l,r;
        cin >> l >> r;
        remove(tree_removed, l, r);
    }
    int left_trees = 0;
    for(int i = 0; i <= L; i++)if(!(tree_removed[i])) left_trees++;
    cout << left_trees;
}
int main(){solve(); return 0;}