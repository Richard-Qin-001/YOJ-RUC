#include <iostream>
#include <map>

using namespace std;

map<char, int> color_map = {{'b', 1}, {'t', 2}, {'w', 3}};

bool check_mianzi(int counts[4][10], int required_mianzi){
    if (required_mianzi == 0) return true;
    int c = 0, n = 0;
    for(c = 1; c <= 3; c++)for(n = 1 ; n <= 9; n++)if(counts[c][n] > 0) goto found_start_card;
    return false;
found_start_card:
    if (counts[c][n] >= 3){
        counts[c][n] -=3;
        if (check_mianzi(counts, required_mianzi-1)){
            counts[c][n] +=3;
            return true;
        }
        counts[c][n] += 3;
    }
    if(n <= 7 && counts[c][n] >= 1 && counts[c][n+1] >= 1 && counts[c][n+2] >= 1){
        counts[c][n]--;
        counts[c][n+1]--;
        counts[c][n+2]--;
        if (check_mianzi(counts, required_mianzi-1)){
            counts[c][n]++;
            counts[c][n+1]++;
            counts[c][n+2]++;
            return true;
        }
        counts[c][n]++;
        counts[c][n+1]++;
        counts[c][n+2]++;
    }

    return false;
}

void process(){
    int counts[4][10] = {0};
    for(int i = 0; i < 8; i++){
        char color;
        int number;
        cin >> color >> number;
        counts[color_map[color]][number]++;
    }
    for(int c = 1; c <= 3; c++)for(int n = 1; n <= 9; n++){
        if(counts[c][n] >= 2){
            counts[c][n] -= 2;
            if (check_mianzi(counts, 2)) {
                    cout << "YES" << endl;
                    counts[c][n] += 2;
                    return;
                }
                counts[c][n] += 2;
        }
    }
    cout << "NO" << endl;
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)process();
}
int main(){ios_base::ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}