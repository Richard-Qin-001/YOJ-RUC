# include <iostream>

int main(){
    using namespace std;
    int m, n, sum = 0;
    char ch;
    cin >> m >> ch >> n;
    for (int i = m + 1; i <= n - 1; i++){
        if (i % 2 == 0){
        }
    else{
        sum += i;
    }
    }
    cout << sum << endl;
    return 0;
}