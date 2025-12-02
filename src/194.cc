#include <bits/stdc++.h>
using namespace std;

int main(){
    int d, h;
    cin >> d >> h;
    vector<char> list = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    string result = "";
    while (d >0){
        int t = d % h;
        result += list[t];
        d /= h;
    }
    reverse(result.begin(), result.end());
    cout << result << endl;
    return 0;
}