#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student{
    int sno;
    int count;
    int rank;
};

bool compareForLine(const Student&a, const Student&b){ return a.count > b.count;}
bool compareForOutput(const Student&a, const Student&b){
    if(a.count != b.count) return a.count > b.count;
    else return a.sno < b.sno;
}

bool judge(const int& index, const vector<int>& problems){
    for (auto&c : problems) if (c == index) return true;
    return false;

}

void solve(){
    int n, m, k;
    cin >> n;
    vector<int> problems(n);
    for (auto&c : problems) cin >> c;
    cin >> m >> k;
    vector<Student> students(m);
    for (auto&c : students){
        int p;
        cin >> c.sno >> p;
        // vector<int> finished_problems(p);
        for (int i = 0; i < p; i++){
            int index = 0;
            cin >> index;
            if (judge(index, problems)) {
                c.count++;
                // finished_problems.push_back(index);
            }
        }
    }
    sort(students.begin(), students.end(), compareForLine);
    sort(students.begin(), students.end(), compareForOutput);

    students[0].rank = 1;
    for (size_t i = 1; i < students.size(); ++i) {
        if (students[i].count == students[i-1].count) {
            students[i].rank = students[i-1].rank;
        } else {
            students[i].rank = students[i-1].rank + 1;
        }
    }

    int out_len = 0;
    for (auto&c : students){
        if (c.rank <= k) out_len++;
    }

    for(int i = 0; i < out_len; i++) {
        cout << students[i].sno;
        if (i < out_len - 1) {
            cout << " ";
        }
    }
}

int main(){solve();return 0;}