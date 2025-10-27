#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> large_numplus(const vector<int>&a, const vector<int>&b){
    vector<int> result;
    vector<int> ar = a; vector<int> br =b;
    reverse(ar.begin(), ar.end());
    reverse(br.begin(), br.end());
    int x, y, z = 0;
    size_t la = ar.size(), lb = br.size(), max_len = max(la,lb);
    result.assign(max_len, 0);
    size_t i = 0;
    for(i; i < max_len; i++){
        x = (i < la) ? a[i] : 0;
        y = (i < lb) ? b[i] : 0;
        result[i] += (x + y + z) % 10;
        z = (x + y + z) / 10;
    }

    if (z != 0) result.push_back(z);
    // size_t index = result.size() - 1;
    // while(result[index] =0 ) result.pop_back();
    // reverse(result.begin(), result.end());
    return result;
}

vector<int> large_numpower(const vector<int>&a){
    vector<int> result;
    int carry = 0;
    for (int digit : a) {
        int temp = digit * 2 + carry;
        result.push_back(temp % 10);
        carry = temp / 10;
    }
    if (carry != 0) {
        result.push_back(carry);
    }
    return result;
}

vector<int> ll2vector(const long long&n){
    vector<int> result;
    if (n == 0) {
        result.push_back(0);
        return result;
    }
    else {
        long long tmp = n;
        while(tmp > 0){
            int digit = tmp % 10;
            result.push_back(digit);
            tmp = tmp / 10;
        }
        // reverse(result.begin(), result.end());
        return result;
    }
}

vector<int> F(const long long&n){
    if (n == 1) return {1};
    vector<int> fn_minus_1 = {5};
    vector<int> fn;
    if (n == 2) return {5};
    for(size_t i = 3; i <= n; i++){
        fn = large_numplus(large_numpower(fn_minus_1), ll2vector(2 *i - 1));
        fn_minus_1 = fn;
    }
    return fn;
}

void solve(){
    long long n;
    cin >> n;
    vector<int> result = F(n);
    reverse(result.begin(), result.end());
    for(auto&c : result) cout << c;
    cout << endl;
}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}