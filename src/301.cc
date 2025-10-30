#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

vector<int> scores;
vector<vector<int>> intervals;
int n, m, g;
int intervalnum;


void process_intervals(){
    vector<int> tmp = {0, 0};
    for(int i = 0; i < m; i++){
        tmp = {intervalnum * (i+1), 0};
        intervals.push_back(tmp);
    }
}

void process_scores(){
    sort(scores.begin(), scores.end());
    int index = 0;
    for(int s : scores){
        int index;
        if (s == 100) {
            index = m - 1;
        } else {
            index = s / intervalnum;
        }
        intervals[index][1]++;
    }
}

bool compare(const vector<int>&row1, const vector<int>&row2){
    if(row1[1] != row2[1])return row1[1] > row2[1];
    else return row1[0] < row2[0];
}

void task1(){
    vector<vector<int>> intervals_c = intervals;
    sort(intervals_c.begin(), intervals_c.end(), compare);
    for(const auto&t:intervals_c){
        if(t[1] > 0){
            int upper_bound = t[0];
            int lower_bound = upper_bound - intervalnum;
            cout << "[";
            cout << setfill(' ') << setw(2) << lower_bound;
            cout << ",";
            if (upper_bound == 100)cout << "100]: "; 
            else {
                cout << setfill(' ') << setw(3) << upper_bound; 
                cout << "): ";
            }
            cout << t[1] << endl;
        }       
    }
}

void task2(){
    int largest = 0;
    int largest_num = 0;
    vector<vector<int>> intervals_c = intervals;
    for(int i = 0; i < m; i++)if(intervals_c[i][1] > largest){largest = intervals_c[i][1];largest_num = i;}
    if(largest > 50){
        double multiplier = 50.0 / (double)largest;
        for(int i = 0; i < m; i++)intervals_c[i][1] = (int)floor(intervals_c[i][1] * multiplier);
        intervals_c[largest_num][1] = 50;
    }
    for(const auto&t:intervals_c){
        int upper_bound = t[0];
        int lower_bound = upper_bound - intervalnum;
        cout << "[";
        cout << setfill(' ') << setw(2) << lower_bound;
        cout << ",";
        if (upper_bound == 100)cout << "100]:"; 
        else {
            cout << setfill(' ') << setw(3) << upper_bound; 
            cout << "):";
        }
        for(int i = 0; i < t[1]; i++) cout<<"*";
        cout << endl;
    }
    
}

void solve(){
    cin >> n >> m >> g;
    scores.assign(n, 0);
    intervalnum = 100 / m;
    for(auto&c:scores) cin >> c;
    process_intervals();
    process_scores();
    if(g == 1) task1();
    else if(g == 2) task2();
    else if(g == 0){
        task1();
        cout << endl;
        task2();
    }
}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve(); return 0;}