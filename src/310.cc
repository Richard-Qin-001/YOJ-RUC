#include <iostream>

using namespace std;

int judge(int a){
    int ac = a;
    int ap = a * a;
    bool status = true;
    while(a > 0){
        int current_a = a % 10;
        int current_ap = ap % 10;
        if(current_a != current_ap) status = false;
        a = a / 10;
        ap = ap / 10;
    }
    if(status) return ac;
    else return 0;
}
void solve(){
    int a, b;
    cin >> a >> b;
    long long sum = 0;
    for(int i = a; i <= b; i++)sum += judge(i);
    cout << sum << endl;
}
int main(){solve(); return 0;}