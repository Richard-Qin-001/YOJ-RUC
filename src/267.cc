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
    if(a.sex != b.sex)return a.sex > b.sex;
}

void solve(){
    int year, n, m;
    cin >> year >> n >> m;
    vector<Baby> babys(n);
    for(int i = 0; i < n; i++){
        Baby baby;
        cin >> baby.id >> baby.month >> baby.day >> baby.sex;
        babys[i] = baby;
    }
    Week week1;
    
}