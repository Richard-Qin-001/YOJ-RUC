# include <iostream>
# include <cmath>
using namespace std;

int get_number(int n){
    int count = 0;
    while(n != 0){
        n = n/10;
        count ++;
    }
    return count;
}

int main(){
    int a, b;
    long long sum = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++){
        if ((long((i * (i - 1))) % long(pow(10,get_number(i)))) == 0){
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}