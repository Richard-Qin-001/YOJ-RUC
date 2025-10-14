# include <iostream>

int main(){
    using namespace std;
    int num = 1;
    for (int i = 1; i <= 10; i++){
        num *= i;
    }
    cout << num << endl;
    return 0;
}