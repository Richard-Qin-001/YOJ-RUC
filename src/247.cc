#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string X;
string W;
ll large_count = 0;
vector<ll> pow_10;

void generate_pow10(){
    pow_10.assign(11, 0);
    pow_10[0] = 1;
    for(int i = 0; i < 10; i++)pow_10[i+1] = pow_10[i] * 10;
}

void DFS(int index, bool is_greater){
    if(is_greater){
        int len = X.length();
        int q_count = 0;
        for(int i = index; i < len; i++)if(X[i] == '?')q_count++;
        large_count += pow_10[q_count];
        return;
    }
    if(index == X.length()) return;
    if(X[index] == '?'){
        for(char c = '0'; c <= '9'; c++){
            if(c > W[index]) DFS(index + 1, true);
            else if (c == W[index]) DFS(index + 1, false);
        }
    }else{
        if(X[index] > W[index]) DFS(index + 1, true);
        else if(X[index] == W[index]) DFS(index + 1, false);
    }
    
}

void solve(){
    generate_pow10();
    while (true){
        getline(cin, X);
        if(X == "#") return;
        getline(cin, W);
        DFS(0, false);
        cout << large_count << endl;
        large_count = 0;
    }
}

int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}