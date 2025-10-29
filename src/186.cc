# include <iostream>
# include <cstring>
# include <algorithm>

using namespace std;

void num_reverse(string&num, int l, int r){
    if(l >= r) return;
    char *pl = &num[l];
    char *pr = &num[r];
    char tmp = *pr;
    *pr = *pl;
    *pl = tmp;
    num_reverse(num, l+1, r-1);
}

void solve(){
    string N;
    cin >> N;
    bool negative_status = false;
    if(N[0] == '-') {
        negative_status = true;
        N.erase(0,1);
    }
    num_reverse(N, 0, N.length() - 1);
    while (N[0] == '0')N.erase(0, 1);
    if(negative_status) N.insert(N.begin(), '-');
    cout << N;
}
int main(){solve(); return 0;}