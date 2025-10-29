#include <iostream>
#include <vector>

using namespace std;

int ch2int(char ch){
    int num = 0;
    num = (int)ch - '0';
    return num;
}

void solve(){
    string d;
    cin >> d;
    vector<int> num;
    for(int i = 0; i < 4; i++)num.push_back(ch2int(d[i]));
    for(auto&c:num) c = (c + 5) % 10;
    swap(num[0], num[3]);
    swap(num[1], num[2]);
    while (num[0] == 0)num.erase(num.begin());
    for(auto&c:num) cout << c;
    cout << endl;
}

int main(){solve();return 0;}