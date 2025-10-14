# include <iostream>
using namespace std;

int main(){
    int a, b, c, d, state = -1;
    cin >> a >> b >> c >> d;
    int array[8] = {120, 40, 85, 50, 100, 140, 70, 100};
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            for (int k = 0 ; k < 8; k++){
                for (int m = 0; m < 8; m ++){
                    if (i == j || i == k || i == m || j == k || j == m || k == m) continue;
                    else if (a > array[i] || b > array[j] || c > array[k] || d > array[m]) continue;
                    else {
                        state = 1;
                        cout << i+1 << " " << j+1 << " " << k+1 << " " << m+1 << endl;
                    }
                }
                }
            }
        }
    if (state == -1) cout << state;
    return 0;
    }
