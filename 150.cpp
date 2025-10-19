#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
    int rank;
    int id;
    int score;
};

bool compareForLine(const Student& a, const Student& b){
    return a.score > b.score;
}
bool compareForOutput(const Student& a, const Student& b){
    if (a.score != b.score) return a.score > b.score;
    else return a.id < b.id;
}

void makerank(vector<Student>& students){
    students[0].rank = 1;

    for (size_t i = 1; i < students.size(); ++i) {
        if (students[i].score == students[i - 1].score) students[i].rank = students[i - 1].rank;
        else students[i].rank = i + 1;
        }
}

void solve(){
    int n;
    if (!(cin >> n)) return;
    vector<Student> students(n);
    for (auto& c : students) cin >> c.id >> c.score;

    sort(students.begin(), students.end(), compareForLine);
    sort(students.begin(), students.end(), compareForOutput);

    makerank(students);

    for (auto&c : students) cout << c.rank << " " << c.id << " " << c.score << endl;
}

int main(){solve(); return 0;}