#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    ll total_min_volatility = 0;
    multiset<int> history_revenues;
    int a1;
    cin >> a1;
    total_min_volatility += a1;
    history_revenues.insert(a1);
    for(int i = 2; i <= n; i++){
        int ai = 0;
        cin >> ai;
        auto it_next = history_revenues.lower_bound(ai);
        ll min_volatility_i = -1;
        if (it_next != history_revenues.end()) {
            min_volatility_i = (ll)(*it_next) - ai;
        }
        if (it_next != history_revenues.begin()) {
            auto it_prev = prev(it_next); 
            ll current_diff = ai - (ll)(*it_prev);
            if (min_volatility_i == -1 || current_diff < min_volatility_i) {
                min_volatility_i = current_diff;
            }
        }
        total_min_volatility += min_volatility_i;
        history_revenues.insert(ai);
    }
    cout << total_min_volatility << endl;
}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve(); return 0;}