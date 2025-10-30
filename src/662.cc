#include <iostream>

using namespace std;

void solve(){
    string name;
    int score1, score2;
    char a, b;
    int n;
    cin >> name >> score1 >> score2 >> a >> b >> n;
    int sum = 0;
    if(score1 >= 80 && n >= 1) sum += 6000;
    if(score1 >= 85 && score2 >= 80) sum += 5000;
    if(score1 >= 90) sum += 4000;
    if(score1 >= 85 && b == 'Y') sum += 2500;
    if(score2 >= 80 && a == 'Y') sum += 950;
    cout << name << " " << sum << endl;
}
int main(){solve(); return 0;}