#include <iostream>
#include <vector>
#include <algorithm>

struct Student
{
    std::string id;
    bool status = false;
};

using namespace std;

bool compare(const Student&a, const Student&b){return a.id < b.id;}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<Student> students(n);
    vector<Student> visitors;
    for (auto&c : students){
        cin >> c.id;
        int sum = 0;
        for(auto&ch : c.id) sum += (int)ch - 48;
        if (sum % k == 0) c.status = true;
        if (c.status) visitors.push_back(c);  
    }
    sort(visitors.begin(), visitors.end(), compare);
    cout << visitors.size() << endl;
    for (auto&c : visitors) cout << c.id << endl;
}
int main(){solve();return 0;}