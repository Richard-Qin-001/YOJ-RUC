#include <iostream>

using namespace std;

int main(){
    int sum = 0;
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        string str;
        int price;
        int num;
        cin >> str >> price >> num;
        sum += price * num;
    }
    cout << sum << endl;
    return 0;
}