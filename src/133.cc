#include <iostream>
#include <map>

using namespace std;

void solve(){
    int N, D, Q;
    cin >> N >> D;
    int I = N / D, R = N % D;
    string result = to_string(I);
    if(R == 0) {
        result += ".0";
        cout << result << endl;
        return;
    }
    result += ".";
    map<int, int> remainder_map;
    int index = 0;
    while (R != 0)
    {
        if(remainder_map.count(R)){
            int start_index = remainder_map[R];
            int len_before_decimal = result.find('.') + 1;
            result.insert(len_before_decimal + start_index, 1, '(');
            result += ")";
            cout << result << endl;
            return;
        }
        remainder_map[R] = index;
        R *= 10;
        Q = R / D;
        R = R % D;
        result += to_string(Q);
        index++;
    }
    cout << result << endl;
    return;
}
int main(){solve(); return 0;}