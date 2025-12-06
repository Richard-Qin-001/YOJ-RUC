#include <bits/stdc++.h>
using namespace std;

struct Candidate
{
    int id;
    string name;
    char sex;
    int age;
    int number;
};


int main(){
    vector<Candidate> candidates(3);
    for(int i = 0; i < 3; i++)cin >> candidates[i].id >> candidates[i].name >> candidates[i].sex >> candidates[i].age >> candidates[i].number;
    sort(candidates.begin(), candidates.end(), [](const Candidate&a, const Candidate&b){return a.number > b.number;});
    for(int i = 0; i < 3; i++)cout << candidates[i].id << "," << candidates[i].name << "," << candidates[i].sex << "," << candidates[i].age << "," << candidates[i].number << endl;
}