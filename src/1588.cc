#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct Candidate
{
    string id;
    int rank = 1;
    double force = 0;
    double power = 1;
    double current_force = 0;
    ll have_won = 0;
    ll credit = 0;
};

bool compare(const Candidate&a, const Candidate&b){
    if(a.credit != b.credit) return a.credit > b.credit;
    if(a.have_won != b.have_won) return a.have_won >b.have_won;
    if(a.id != b.id) return a.id < b.id;
    return false;
}

void sovle(){
    int n;
    cin >> n;
    vector<Candidate> candidates(n);
    for(auto&can:candidates) {
        cin >> can.id >> can.force;
        can.current_force = can.force * can.power;
        }
    int a = 0, b = 1;
    while (a < n && b < n)
    {
        if(candidates[a].current_force >= candidates[b].force){
            candidates[a].power *= 0.75;
            candidates[a].current_force = candidates[a].force * candidates[a].power;
            int fun_credit = 5-candidates[b].have_won;
            if (fun_credit < 1) fun_credit = 1;
            int extern_credit = candidates[a].have_won;
            if (extern_credit > 5) extern_credit = 5;
            candidates[a].credit += fun_credit + extern_credit;
            candidates[a].have_won += 1;
            b++;
        }
        else{
            candidates[b].power *= 0.75;
            candidates[b].current_force = candidates[b].force * candidates[b].power;
            int fun_credit = 5-candidates[a].have_won;
            if (fun_credit < 1) fun_credit = 1;
            int extern_credit = candidates[b].have_won;
            if (extern_credit > 5) extern_credit = 5;
            candidates[b].credit += fun_credit + extern_credit;
            candidates[b].have_won += 1;
            a = b;
            b = a+1;
        }
    }
    sort(candidates.begin(), candidates.end(), compare);
    int countn = 0;
    for(int i = 1; i < n; i++){
        if(candidates[i].credit == candidates[i-1].credit) {
            candidates[i].rank = candidates[i-1].rank;
            countn++;
        }
        else {
            candidates[i].rank = candidates[i-1].rank + 1 + countn;
            countn = 0;
        }
    }
    for(auto&can:candidates)cout <<can.rank << " " << can.id << " " << can.credit << endl;
}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); sovle(); return 0;}