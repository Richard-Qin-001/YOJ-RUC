#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isSame(vector<int> prices){
    int l = prices.size();
    for(int i = 0; i < l-1; i++)if(prices[i] != prices[i+1]) return false;
    return true;
}

void solve(){
    int m;
    cin >> m;
    vector<int> prices(m);
    for(int i = 0; i < m ;i ++)cin >> prices[i];
    int count = 1;
    while (!(isSame(prices)))
    {
        vector<int> tmp = prices;
        for(int i = 1; i < m-1; i++){
            tmp[i] = (int)floor((prices[i-1] + prices[i] + prices[i+1]) / 3);
        }
        tmp[0] = (int)floor((prices[0] + prices[1]) / 2);
        tmp[m-1] = (int)floor((prices[m-1] + prices[m-2]) / 2);
        prices = tmp;
        count++;
    }
    cout <<count << endl;
}
int main(){
    solve();
    return 0;
}