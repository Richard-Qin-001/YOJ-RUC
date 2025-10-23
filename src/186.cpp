# include <iostream>
# include <string>
# include <algorithm>

using namespace std;

void reverse_Integer_String(){
    long long N;
    if (!(cin >> N)) return;

    string s = to_string(N);
    if (s[0] == '-'){
        reverse(s.begin() + 1, s.end());
    }
    else{
        reverse(s.begin(), s.end());
    }
    long long result = stoll(s);
    cout << result << endl;
}

int main(){
    reverse_Integer_String();
    return 0;

}