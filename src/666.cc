#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

bool compare(const vector<ll> & row1, const vector<ll> & row2){
    if(row1[1] != row2[1]) return row1[1] < row2[1];
    else return row1[0] < row2[0];
}

void solve(){
    int n;
    cin >> n;
    vector<vector<ll>> students;
    for(int i = 0; i < n ; i++){
        ll id, day;
        cin >> id >> day;
        vector<ll> student = { id, day};
        students.push_back(student);
    }
    sort(students.begin(), students.end(), compare);
    int p = static_cast<int>(ceil(n * 0.3));
    ll day_limit = students[p - 1][1];
    ll final_deadline_T = day_limit + 180;
    int qualified_count = 0;
    for (int i = 0; i < n; ++i) {
        if (students[i][1] <= day_limit)qualified_count++;
        else break; 
    }
    cout << final_deadline_T << endl;
    for(int i = 0; i <qualified_count; i++)cout << students[i][0] << " " << students[i][1] << endl;
}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}