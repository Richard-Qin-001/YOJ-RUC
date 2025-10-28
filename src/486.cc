#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> list(4);

int getrank(char a){
    for(int i = 0; i < 4; i++){
        if(list[i] == a) return i;
    }
    return 3;
}

bool compare(const vector<char>&a, const vector<char>&b){
    int n = a.size();
    for(int i = 0; i < n; i++){
        int ranka = getrank(a[i]), rankb = getrank(b[i]);
        if(ranka < rankb) return true;
        else if(ranka > rankb) return false;
    }
    return false;
}

void solve(){
    int N;
    cin >>N;
    for(auto&c:list) cin >> c;
    vector<vector<char>> matrix;
    for(int i = 0; i < N; i++){
        vector<char> input;
        string inp;
        cin >> inp;
        for(auto&c:inp) input.push_back(c);
        matrix.push_back(input);
    }
    
    sort(matrix.begin(), matrix.end(), compare);
    int m = matrix[0].size();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < m; j++){
            cout << matrix[i][j];
        }
        cout << endl;
    }
}
int main(){solve(); return 0;}