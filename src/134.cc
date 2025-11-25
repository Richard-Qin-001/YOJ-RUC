#include <bits/stdc++.h>
using namespace std;

struct Guess
{
    int num;
    int correct_digit;
    int correct_pos;
};


void solve(){
    int N;
    cin >> N;
    vector<Guess> guess_list(N);
    for(int i = 0; i < N; i++){
        Guess guess;
        cin >> guess.num >> guess.correct_digit >> guess.correct_pos;
        guess_list[i] = guess;
    }
    vector<int> solutions;
    for(int i = 1000; i <= 9999; i++){
        bool status = true;
        for(int j = 0; j < N; j++){
            string x = to_string(i), y = to_string(guess_list[j].num);
            int digit_count = 0, pos_count = 0;
            for(int k = 0; k < 4; k++)if(x[k] == y[k])pos_count++;
            int count_x[10] = {0}, count_y[10] = {0};
            for(int k = 0; k < 4; k++)count_x[x[k] - '0'] ++, count_y[y[k] - '0'] ++;
            for(int k = 0; k < 10; k++)digit_count += min(count_x[k], count_y[k]);
            if(digit_count != guess_list[j].correct_digit || pos_count != guess_list[j].correct_pos){
                status = false;
                break;
            }
        }
        if(status) solutions.push_back(i);
    }
    if(solutions.size() != 1) cout << "Not sure" << endl;
    else cout << solutions[0] << endl;
}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}