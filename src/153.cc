#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
int result = 0;

vector<ll> fact(21, 1);
void calculate_permutation(){
    for (int i = 1; i < 21; i++)fact[i] = fact[i-1] * i;
}

// void process(int start, const vector<int>&particular){
//     vector<int> standart = particular;
//     sort(standart.begin() + start,standart.end());
//     for(int i = start; i < particular.size(); i++){

//     }
// }

void solve(){
    int n;
    cin >> n;
    vector<int> particular(n);
    for(auto&i:particular) cin >> i;
    calculate_permutation();
    ll rank_sum = 0;
    vector<bool> used(n + 1, false);
    for(int i = 0; i < n;i ++){
        int a_i = particular[i];
        ll k_i = 0;
        for(int j = 1; j < a_i; j++) if(!used[j]) k_i++;
        int remaining_positions = n - 1 - i;
        ll permutation_block_size = fact[remaining_positions];
        rank_sum += permutation_block_size * k_i;
        used[a_i] = true;
    }
    ll final_rank = rank_sum+1;
    cout << final_rank << endl;
}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}