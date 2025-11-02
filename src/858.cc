#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

struct num {
    string raw; 
    int count;
    string final;
};

string strreverse(const string& n) {
    string n_n = n;
    int len = n_n.length();
    for(int i = 0; i < len / 2; ++i) {
        swap(n_n[i], n_n[len - 1 - i]);
    }
    return n_n;
}

bool judge(const string& n) {
    int len = n.length();
    for (int i = 0; i < len / 2; ++i) {
        if (n[i] != n[len - 1 - i]) return false;
    }
    return true;
}

string stringAdd(const string& s1, const string& s2) {
    string result = "";
    int i = s1.length() - 1;
    int j = s2.length() - 1;
    int carry = 0;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += s1[i--] - '0';
        if (j >= 0) sum += s2[j--] - '0';
        
        result += char(sum % 10 + '0'); 
        carry = sum / 10; 
    }
    
    return strreverse(result);
}

void process(num& n) {
    if (judge(n.final)) {
        n.count = 0;
        return;
    }

    n.count = 0;
    while (!judge(n.final)) {

        string n_r = strreverse(n.final);

        n.final = stringAdd(n.final, n_r);
        n.count++;
    
    }
}

bool compare(const num& a, const num& b) {
    if (a.count != b.count) {
        return a.count > b.count; 
    }
    if (a.final != b.final) {
        if (a.final.length() != b.final.length()) {
            return a.final.length() < b.final.length();
        }
        return a.final < b.final;
    }
    
    if (a.raw.length() != b.raw.length()) {
        return a.raw.length() < b.raw.length();
    }
    return a.raw < b.raw;
}

void solve() {
    vector<num> nums(10);
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 10; ++i) {
        cin >> nums[i].raw;
        nums[i].final = nums[i].raw;
        process(nums[i]);
    }
    
    sort(nums.begin(), nums.end(), compare);
    
    for (const auto& c : nums) {
        cout << c.raw << " " << c.count << " " << c.final << "\n";
    }
}

int main() {
    solve();
    return 0;
}