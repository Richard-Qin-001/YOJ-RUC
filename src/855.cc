#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct Score
{
    string alien_score;
    vector<int> earth_score;
};


vector<int> large_number_add(const vector<int>&a, const vector<int>&b){
    vector<int> result;
    int carry = 0, i = 0, j = 0;
    while(i < a.size() || j < b.size() || carry){
        int sum = carry;
        if (i < a.size()) {
            sum += a[i];
            i++;
        }
        if (j < b.size()) {
            sum += b[j];
            j++;
        }
        result.push_back(sum % 10);
        carry = sum / 10;
    }
    return result;
}

vector<int> large_number_multiply(const vector<int>& a, int b){
    if (b == 0) return {0};
    if (a.empty()) return {};

    vector<int> result;
    int carry = 0;

    for(int digit:a){
        ll product = (ll)digit * b + carry;
         result.push_back(product % 10);
         carry = product / 10;
    }
    while (carry) {
        result.push_back(carry % 10);
        carry /= 10;
    }
    return result;
}

vector<int> alien2earth(string alien_score, map<char, int>sys, int R){
    vector<int> earth_score = {0};
    for(char&c:alien_score){
        int value = sys.at(c);
        earth_score = large_number_multiply(earth_score, R);
        earth_score = large_number_add(earth_score, {value});
    }
    return earth_score;
}
bool compare(const Score&s1, const Score&s2){
    const vector<int>& a = s1.earth_score;
    const vector<int>& b = s2.earth_score;
    if(a.size() != b.size()) return a.size() > b.size();
    for(int i = a.size() - 1; i >= 0; i--)if(a[i] != b[i]) return a[i] > b[i];
    return false;
}

void solve(){
    int n;
    string alien_sys;
    cin >> n >> alien_sys;
    int R = alien_sys.length();
    map<char, int> alien_system;
    for(int i = 0; i < alien_sys.length(); i++)alien_system[alien_sys[i]] = i;
    vector<Score> scores;
    for(int i = 0; i < n; i++){
        string alien_score;
        cin >> alien_score;
        Score score;
        score.alien_score = alien_score;
        score.earth_score = alien2earth(alien_score, alien_system, R);
        scores.push_back(score);
    }
    sort(scores.begin(), scores.end(), compare);
    for(int i = 0; i < n; i++) cout << scores[i].alien_score << (i == n-1 ? "" : " ");
    cout << endl;
    const vector<int>& min_score_decimal = scores.back().earth_score;
    for(int i = min_score_decimal.size() - 1; i >= 0; i--)cout << min_score_decimal[i];
    cout << endl;
}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}