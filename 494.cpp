#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

void solve(){
    int n;
    cin >> n;
    map<int, int> goods;
    for (int i = 1; i < n+1; i++){
        int price = 0;
        cin >> price;
        goods[i] = price;
    }
    int x;
    cin >> x;
    for (int i = 1; i < n+1; i++){
        for (int j = i+1; j < n+1; j++){
            if (goods[i] + goods[j] == x){
                cout << i << " " << j;
                return;
            }
        }
    }
}

int main(){solve();return 0;}