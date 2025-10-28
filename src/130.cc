#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> transform(const vector<ll>&s, const vector<ll>& d){
    ll n = s.size() * 2;
    vector<ll> origin(n);
    for(size_t i = 0; i < n; i++){
        if(i % 2 == 0) origin[i] = (s[i/2] + d[i/2])/2;
        else origin[i] = (s[(i-1)/2] - d[(i-1)/2])/2;
    }
    return origin;
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> result(n),s, d;
    for(auto&c:result) cin >> c;
    ll index = 1;
    while(index < n){
        s.assign(index, 0);
        d.assign(index, 0);
        for(size_t i = 0; i < index; i++) s[i] = result[i];
        for(size_t i = index; i < index * 2; i++) d[i-index] = result[i];
        vector<ll> tmp = transform(s, d);
        for(size_t i = index * 2; i < n; i++) tmp.push_back(result[i]);
        result = tmp;
        index *= 2;
    }
    
    for(size_t i = 0; i < n - 1; i++) cout << result[i] << " ";
    cout << result[n-1] << endl;
}
int main(){ios::sync_with_stdio(false);cin.tie(NULL);solve(); return 0;}