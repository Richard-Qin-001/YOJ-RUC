#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
    int id;
    // vector<int> score;
    int sum;
};

bool judge(const int& a){
    return (a >= 60);
}

bool compareForLine(const Student& a, const Student& b){
    return a.sum > b.sum;
}

bool compareForOutput(const Student& a, const Student& b){
    if (a.sum != b.sum) return a.sum > b.sum;
    else return a.id < b.id;
}

void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> lecture(m);
    for (auto&i : lecture){
        cin >> i;
    }
    vector<Student> students(n);
    for (int i = 0; i < n; i++){
        cin >> students[i].id;
        for (int j = 0; j < m; j++){
            int score = 0;
            cin >> score;
            if (judge(score)){
                students[i].sum += lecture[j];
            }
        }
    }

    sort(students.begin(),students.end(), compareForLine);
    sort(students.begin(),students.end(), compareForOutput);

    for (const auto&c : students){
        cout << c.id << " " << c.sum << endl;
    }


}

int main(){
    solve();
    return 0;
}