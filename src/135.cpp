#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int ch2int(const char& ch){
    int ch_int = (int)ch - 48;
    return ch_int;
}

bool compare(const string& a, const string&b){
    int return_value = 0;
    int status = 0;
    for (int i = 6; i < 14; i++){
        if (ch2int(a[i]) > ch2int(b[i])){
            return_value = 1;
            status = 1;
            break;
        }
        else if (ch2int(a[i]) < ch2int(b[i])){
            return_value = 0;
            status = 1;
            break;
        }
    }
    if (status == 0){
        for (int i = 0; i < 18; i++){
            if (ch2int(a[i]) > ch2int(b[i])){
            return_value = 1;
            break;
        }
        else if (ch2int(a[i]) < ch2int(b[i])){
            return_value = 0;
            break;
        }
        }
    }
    return return_value;
}

void solve(){
    int n;
    cin >> n;
    vector<string> list(n);
    for (auto&c : list) cin >> c;
    sort(list.begin(), list.end(), compare);
    for (auto&c : list) cout << c << endl;

}
int main(){solve(); return 0;}