#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Baby{
    int id;
    int month;
    int day;
    int sex;
};
struct Week{
    int start_month;
    int start_day;
    int end_month;
    int end_day;
    int total_babys;
    int total_boys;
};


bool compare_date(const Baby& a, const Baby& b){
    if(a.month != b.month)return a.month < b.month;
    if(a.day != b.day)return a.day < b.day;
    return a.sex > b.sex;
}

bool compare_week(const Week&a, const Week&b){
    if(a.total_babys != b.total_babys) return a.total_babys > b.total_babys;
    if(a.start_month != b.start_month) return a.start_month < b.start_month;
    return a.start_day < b.start_day;
}

bool is_leap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int get_days_in_month(int year, int month) {
    static const map<int, int> days = {{1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};
    if (month == 2 && is_leap(year)) return 29;
    return days.at(month);
}

void solve(){
    int year, n, m;
    cin >> year >> n >> m;
    vector<Baby> babys(n);
    for(int i = 0; i < n; i++)cin >> babys[i].id >> babys[i].month >> babys[i].day >> babys[i].sex;
    sort(babys.begin(), babys.end(), compare_date);
    ll total_days = 0;
    for(int i = 1969; i <year; i++)total_days += is_leap(i) ? 366 : 365;
    
    int current_weekday = (3 + total_days % 7) % 7;
    Week current_week = {1, 1, 0, 0, 0, 0};
    vector<Week> weeks;
    weeks.resize(48);
    int baby_idx = 0;
    for(int month = 1; month <= 12; month++){
        int days_in_month = get_days_in_month(year, month);
        for(int day = 1; day <= days_in_month; ++day){
            while (baby_idx < n && babys[baby_idx].month == month && babys[baby_idx].day == day) {
                current_week.total_babys++;
                if (babys[baby_idx].sex == 1)current_week.total_boys++;
                baby_idx++;
            }
            current_week.end_month = month;
            current_week.end_day = day;
            if(current_weekday == 6 || (month == 12 && day == days_in_month)){
                weeks.push_back(current_week);
                int next_day = day + 1;
                int next_month = month;
                if (next_day > days_in_month) {
                    next_day = 1;
                    next_month++;
                }
                if (next_month <= 12)current_week = {next_month, next_day, 0, 0, 0, 0};
                else goto end_loop;
            }
            current_weekday = (current_weekday + 1) % 7;
        }
            
    }
    end_loop:;
    sort(weeks.begin(), weeks.end(), compare_week);
    for(int i = 0; i < m; i++){
        cout << "[";
        cout << right << setw(2) << weeks[i].start_month << "." << right << setw(2) << weeks[i].start_day;
        cout << "-";
        cout << right << setw(2) << weeks[i].end_month << "." << right << setw(2) << weeks[i].end_day;
        cout << "]";
        cout << ":";
        cout << weeks[i].total_babys << "(B" << weeks[i].total_boys << ")";
        cout << "\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}