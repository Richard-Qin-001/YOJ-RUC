#include <bits/stdc++.h>
using namespace std;

struct Person
{
    int id;
    int income = 0;
    int gets = 0;
};


int main(){
    int N;
    cin >> N;
    vector<Person> people(N + 1);
    for(int i = 1; i <= N; i++){
        people[i].id = i;
        int outs;
        cin >> outs;
        int id, num, outcome = 0;
        for(int j = 0; j < outs; j++){
            cin >> id >> num;
            people[id].income += num;
            people[id].gets ++;
            outcome += num;
        }
        people[i].income -= outcome;
    }
    sort(people.begin() + 1, people.end(), [](const Person&a, const Person&b){
        if(a.income != b.income)return a.income > b.income;
        if(a.gets != b.gets)return a.gets > b.gets;
        return a.id < b.id;
    });
    for(int i = 1; i <= N; ++i){
        cout << people[i].id << " " << people[i].gets << " " << people[i].income << endl;
    }
    return 0;
}