#include <bits/stdc++.h>
using namespace std;

struct Warehouse
{
    vector<int> code;
    int id;
    int superior_id = 0;
};


extern "C++" int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<Warehouse> warehouses(n + 1);
    for(int i = 1; i <= n; ++i){
        warehouses[i].id = i;
        warehouses[i].code.assign(m, 0);
        for(int j = 0; j < m; ++j)cin >> warehouses[i].code[j];
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(j != i){
                bool status = true;
                for(int k = 0; k < m; ++k){
                    if(warehouses[j].code[k] <= warehouses[i].code[k])status = false;
                }
                if(status){
                    warehouses[i].superior_id = j;
                    break;
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i)cout << warehouses[i].superior_id << endl;
    return 0;
}