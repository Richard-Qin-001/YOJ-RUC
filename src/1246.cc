#include <bits/stdc++.h>
using namespace std;

int main(){
    int b, c, l, r;
    cin >> b >> c >> l >> r;
    vector<int> evens;
    for(int i = l; i <= r; ++i)if(i % 2 == 0)evens.emplace_back(i);
    int total_evens = evens.size();
    vector<int> values(total_evens);
    for(int i = 0; i < total_evens; ++i){
        int point = evens[i];
        values[i] = point * point + b * point + c;
    }
    int s = accumulate(values.begin(), values.end(), 0);
    s *= 2;
    cout << s << endl;
    return 0;
}