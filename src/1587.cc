#include <bits/stdc++.h>
using namespace std;

vector<int> dishes(6), drinks(4);
int total_max, total;

bool check(int i, int j, int k){
    if(i == 1 && j == 3) return false;
    if(i == 5 || j == 5){
        if(k != 3) return false;
    }
    if(i == 2 || j == 2){
        if(k == 1)return false;
    }
    total = dishes[i] + dishes[j] + drinks[k];
    if( total > total_max)  return false;
    return true;
}

int main(){
    for(int i = 1; i <= 5; i++)cin >> dishes[i];
    for(int i = 1; i <=3; i++)cin >> drinks[i];
    cin >> total_max;
    vector<vector<int>> solutions;
    vector<int> solution;
    for(int i = 1; i <= 4; i++){
        for(int j = i + 1; j <= 5; j++){
            for(int k = 1; k <= 3; k++){
                if(check(i, j, k)){
                    solution = {i, j, k, total};
                    solutions.push_back(solution);
                }
            }
        }
    }
    int t = solutions.size();
    if(t == 0){
        cout << "No solution" << endl;
        return 0;
    }
    cout << t << endl;
    sort(solutions.begin(), solutions.end(), [](const vector<int> & a, const vector<int> & b){
        if(a[3] != b[3])return a[3] < b[3];
        return false;
    });
    cout << solutions[0][0] << " " << solutions[0][1] << " " <<  solutions[0][2] << " " << solutions[0][3] << endl;
}