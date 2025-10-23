# include <iostream>
 int main(){
    using namespace std;
    long long x, y, z;
    char ch1, ch2;
    cin >> x >> ch1 >> y >> ch2 >> z;
    long long arr[] = {x, y, z};
    long long temp;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2 - i; j++){
            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << arr[0] << ch1 << arr[1] << ch2 << arr[2] << endl;
    return 0;
 }