#include <iostream>
#include <vector>
#include <map>

using namespace std;

int get_score(const map<int, int>& inputs, const int&score){
    if (score == 2048) {
        return ((inputs.count(4) && inputs.at(4) == 4) && (inputs.count(1) && inputs.at(1) == 2)) ? 2048 : 0;
    }
    
    if (score == 1024) {
        return (inputs.count(4) && inputs.at(4) == 6) ? 1024 : 0;
    }

    if (score == 512) {
        return (inputs.count(1) && inputs.at(1) == 6) ? 512 : 0;
    }

    if (score == 256) {
        return (inputs.count(2) && inputs.at(2) == 6) ? 256 : 0;
    }
    
    if (score == 128) {
        return (inputs.count(4) && inputs.at(4) == 5) ? 128 : 0;
    }

    if (score == 64) {
        return (inputs.count(2) && inputs.at(2) == 5) ? 64 : 0;
    }

    if (score == 32) {
        return (inputs.count(4) && inputs.at(4) == 4) ? 32 : 0;
    }

    if (score == 16) {
        if (inputs.size() != 6) return 0;
        for (const auto& pair : inputs) {
            if (pair.second != 1) return 0;
        }
        return 16;
    }

    if (score == 8) {
        return (inputs.count(4) && inputs.at(4) == 3) ? 8 : 0;
    }

    if (score == 4) {
        return (inputs.count(2) && inputs.at(2) == 4) ? 4 : 0;
    }

    if (score == 2) {
        return (inputs.count(4) && inputs.at(4) == 2) ? 2 : 0;
    }

    if (score == 1) {
        return (inputs.count(4) && inputs.at(4) == 1) ? 1 : 0;
    }
    return 0;
}

void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    long sum_score = 0;
    vector<int> score_list = {
        2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1
    };
    for (int i = 0; i < n; i++){
        map<int,int> inputs;
        for(int j = 0; j < 6; j++){
            int elements;
            cin >> elements;
            inputs[elements] ++;
        }
        int current_score = 0;
        for(auto&c : score_list) {
            current_score = get_score(inputs,c);
            if (current_score != 0) break;
        }
        if (current_score == 0) break;
        else sum_score+=current_score;
    }
    cout << hex;
    cout << sum_score << endl;
}

int main(){solve();return 0;}