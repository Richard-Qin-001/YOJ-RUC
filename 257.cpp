# include <iostream>
using namespace std;
int main(){
    int k;
    double sum;
    cin >> k;
    double i = 0.0;
    while(sum <= k){
        i ++;
        sum += 1.0/i;

    }
    cout << int(i);
    return 0;
}