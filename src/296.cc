#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<string> all_slots;
    for (int day = 1; day <= 7; ++day)for (int period = 1; period <= 7; ++period)all_slots.push_back(to_string(day) + "." + to_string(period));
    unordered_map<string, int> times;
    for (const string &slot : all_slots)times[slot] = 0;
    for(int i = 0; i < n; ++i){
        int m, p;
        cin >> m >> p;
        for(int j = 0; j < p; j++){
            string period;
            cin >> period;
            times[period]++;
        }
    }
    vector<pair<string, int>> time_period;
    time_period.reserve(times.size());
    for(auto&p:times)time_period.push_back(p);
    sort(time_period.begin(), time_period.end(), [](const pair<string, int>&a, const pair<string, int>&b){
        if(a.second != b.second)return a.second < b.second;
        return a.first < b.first;
    });
    int cap = time_period.size();
    for(int i = 0; i < k && i < cap; ++i)cout << time_period[i].first << " " << time_period[i].second << "\n";
    return 0;
}