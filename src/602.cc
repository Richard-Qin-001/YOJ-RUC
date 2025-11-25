#include <bits/stdc++.h>
using namespace std;

vector<int> prime_list;
vector<bool> is_Prime;

void generate_Prime(int n){
    is_Prime.assign(n+1, true);
    is_Prime[0] = is_Prime[1] = false;
    int limit = static_cast<int>(sqrt(n));
    for(int p = 2; p <= limit; p++){
        if(is_Prime[p])for(int i = p * p; i <= n; i += p)is_Prime[i] = false;
    }
    for(int p = 2; p <= n; p++)if(is_Prime[p])prime_list.push_back(p);
}

void solve(){
    int N;
    cin >> N;
    generate_Prime(1000);
    int total = prime_list.size();
    for(int k = 0; k < N; k++){
        int n;
        cin >> n;
        int solution = 0;
        for(int i = 0; i < total; i++)for(int j = i; j < total; j++){
            int a = prime_list[i], b = prime_list[j];
            int c = n - a - b;
            if(c < b) break;
            if(c < 2) continue;
            if(c >= 1000) continue;
            if(!is_Prime[c]) continue;
            if(a == b || a == c || b == c)continue;
            solution++;
        }
        cout << solution;
        if(k != N-1) cout << " ";
    }
}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}