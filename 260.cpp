#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search_func(const vector<int>&array, int target, int&comparisons){
    int low = 0;
    int high = array.size() - 1;
    
    comparisons = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        comparisons++;

        if (target == array[mid]) {
            return mid;
        } else if (target < array[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;

}

void solve(){
    int n, m;
    if (!(cin >> n >> m)) return;
    vector<int> list(n);
    for(auto&c : list) cin >> c;
    sort(list.begin(), list.end());
    int comparison_count = 0;
    int position = binary_search_func(list, m, comparison_count);
    cout << position << endl;
    cout << comparison_count << endl;


}
int main(){solve();return 0;}