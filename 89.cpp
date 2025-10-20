#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Tier
{
    long long boundary;
    double rate;
};


void solve(){
    int n;
    cin >> n;
    vector<Tier> tiers(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> tiers[i].boundary >> tiers[i].rate)) return;
    }
    long long current_profit;
    if (!(cin >> current_profit)) return;
    if (current_profit < 0) {
        cout << "NO" << endl;
        return;
    }
    double total_bonus = 0.0;
    long long previous_boundary = 0;
    for (int i = 0; i < n; ++i) {
        long long current_boundary = tiers[i].boundary;
        double rate = tiers[i].rate;

        if (current_boundary == -1) {
            if (current_profit > previous_boundary) {
                long long profit_amount_in_segment = current_profit - previous_boundary;
                
                total_bonus += (double)profit_amount_in_segment * rate;
            }
            break; 
        }
        if (current_profit > current_boundary) {
            long long profit_amount_in_segment = current_boundary - previous_boundary;
            
            total_bonus += (double)profit_amount_in_segment * rate;
            
            previous_boundary = current_boundary;
        } 
        else if (current_profit > previous_boundary) {
            long long profit_amount_in_segment = current_profit - previous_boundary;
            
            total_bonus += (double)profit_amount_in_segment * rate;
            
            break;
        }
    }
    cout << fixed << setprecision(2) << total_bonus << endl;
}
int main() {solve();return 0;}