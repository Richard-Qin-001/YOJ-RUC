# include <iostream>
# include <string>
int main(){
    using namespace std;
    long a, b, c, d, e;
    int sum = 0;
    cin >> a >> b >> c >> d >> e;
    for (int i = a; i <= b; i++){
        string s = to_string(i);
        if (i % 10 == c && s.length() == e && i % d == 0){
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}