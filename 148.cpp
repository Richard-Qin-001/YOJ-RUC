# include <iostream>
# include <algorithm>
using namespace std;

int main(){
    int n, count = 0;
    cin >> n;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            for (int k = 0; k <= n; k++){
                if (i != j && i != k && j != k){
                    if ( i % 2 == 0){
                        if (i >= min(j, k) && i <= max(j, k)){
                            if ((k) % 10 == 8){
                                int cost = 2 * i + 6 * j + 1 * k;
                                if ( cost * 10> 9 * n && cost <= n){
                                    if (((j >= 1 && j < 10) && (i >= 10 && i < 100)) || (j>=10)){
                                        cout << i << " " << j << " " << k << endl;
                                        count = 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (count == 0) cout << "no answer" << endl;
    return 0;
}