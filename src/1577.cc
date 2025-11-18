#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string rot(string&x){
    string rot_x = x;
    while (rot_x.back() == '0') rot_x.pop_back();
    reverse(rot_x.begin(), rot_x.end());
    int len = rot_x.length();
    for(int i = 0; i < len; i++){
        if(rot_x[i] == '6') rot_x[i] = '9';
        else if(rot_x[i] == '9') rot_x[i] = '6';
    }
    return rot_x;
}

bool judge(int x){
    string X = to_string(x);
    int len = X.length();
    for(int i = 0; i < len; i++)if(X[i] != '0' && X[i] != '1' && X[i] != '6' && X[i] != '8' && X[i] != '9')return false;
    return true;
}



void solve(){
    int N, K = 0;
    cin >> N;
    vector<int> valid_nums;
    for(int i = 1; i < N; i++)if(judge(i)) valid_nums.push_back(i);
    int total_valid = valid_nums.size();
    for(int i = 0; i < total_valid; i++){
        for(int j = i; j < total_valid; j++){
            int a = valid_nums[i], b = valid_nums[j], c = a + b;
            if(c >= N)break;
            bool status = false;
            for(int k = j+1; k < total_valid; k++){
                if (valid_nums[k] == c) {
                    status = true;
                    break;
                }
            }
            if(!status) continue;
            string A = to_string(a), B = to_string(b), C = to_string(c),
            rotA = rot(A), rotB = rot(B), rotC = rot(C);
            int rotAint = stoi(rotA), rotBint = stoi(rotB), rotCint = stoi(rotC);
            if(rotAint+rotBint == rotCint) K++;
        }
    }
    cout << K;
}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 1;}