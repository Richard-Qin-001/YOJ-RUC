# include <iostream>
# include <algorithm>
# include <iomanip>

using namespace std;

int main(){
    int n ;
    cin >> n;
    int tmp;
    int max_time = 0, min_time = 0, sum = 0;
    double average_time = 0;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        sum += tmp;
        max_time = max(max_time, tmp);
        if (i ==0) min_time = tmp;
        min_time = min(min_time, tmp);
    }
    average_time = double(sum) / double(n);
    cout << fixed << setprecision(0);
    cout << max_time << " " <<  min_time << " " << average_time << endl;
    return 0;

}