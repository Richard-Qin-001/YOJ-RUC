#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll transform(string s, int base){
    ll result = 0;
    ll power = 1;
    for(int i = s.length() - 1; i >= 0; i--){
        int digit = s[i] - '0';
        result += digit * power;
        power *= base;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    string p, q, r, all;
    ll pi, qi, ri;
    int start_base = 2;
    for(int i = 0; i < T; ++i){
        cin >> p >> q >> r;
        all = p + q + r;
        start_base = 2;
        for(auto&d:all){
            int digit = d - '0';
            start_base = max(start_base, digit + 1);
        }
        for(int j = start_base; j < 17; ++j){
            pi = transform(p, j), qi = transform(q, j), ri = transform(r, j);
            if(pi * qi == ri){
                cout << j << endl;
                goto end_loop;
            }
        }
        cout << 0 << endl;
        end_loop:
        ;
    }
    return 0;
}