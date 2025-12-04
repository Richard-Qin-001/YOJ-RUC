#include <bits/stdc++.h>
using namespace std;

int match_count[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int get_match(int n){
    if (n == 0) return match_count[0];
    int sum = 0;
    while(n > 0){
        sum += match_count[n % 10];
        n /= 10;
    }
    return sum;
}

bool is_valid(int x) {
    if (x == 0) return true;
    string s = to_string(x);
    return s[0] != '0';
}


int main(){
    int n;
    cin >> n;
    int total = 0;

    for(int A = 0; A <= 1111; ++A){
        if(!is_valid(A))continue;
        int match_A = get_match(A);
        for(int B = 0; B <= 1111; ++B){
            if (!is_valid(B)) continue;
            int match_B = get_match(B);
            if(match_A + match_B + 4 > n)continue;
            int C= A + B;
            if (!is_valid(C)) continue;
            int match_C = get_match(C);
            if(match_A + match_B + match_C + 4 == n)total++;
        }
    }
    cout <<  total << endl;
    return 0;
}