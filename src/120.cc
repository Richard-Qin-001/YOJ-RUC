#include <iostream>
#include <vector>

using namespace std;

vector<int> input(const int &n){
    vector<int> list(n);
    for(auto&c : list) cin >> c;
    return list;
}

void rank_list(vector<int>& list, vector<vector<int>>& log,int& start_index){
    int min_index = 0;
    int min_value = list[start_index];
    int end_index = list.size() - 1;
    bool change = false;
    for(int i = start_index;  i <= end_index; i++){
        if (min_value > list[i]){
            min_index = i;
            min_value = list[i];
            change = true;
        }
    }
    if (change){
        vector<int> tmp_log = {start_index, min_index};
        swap(list[start_index], list[min_index]);
        for(auto&c : list) tmp_log.push_back(c);
        log.push_back(tmp_log);
    }
    start_index++;
    if (start_index == end_index) return;
    rank_list(list, log, start_index);
}

void solve(){
    int n;
    cin >> n;
    vector<int> list = input(n);
    vector<vector<int>> log;
    int start_index = 0;
    rank_list(list, log, start_index);
    int steps = log.size();
    for(int i = steps; i > 0; i--){
        cout << log[i-1][0]+1 << "<->" << log[i-1][1]+1 << ":";
        for(int j = 2; j < n+2; j++){
            if (j != n+1) cout << log[i-1][j] << " ";
            else cout << log[i-1][j] << endl;
        }
    }
    cout << "Total steps:" << steps << endl;
    cout << "Right order:";
    for(int i = 0; i < n; i++){
            if (i != n-1) cout << list[i] << " ";
            else cout << list[i] << endl;
        }
}
int main(){solve(); return 0;}