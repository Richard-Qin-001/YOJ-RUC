# include <iostream>
# include <cmath>

using namespace std;

int juge(int a , int b, int c, int d, int e, int x, long long ans){
    long long true_ans = 0;
    true_ans = a * pow(x, 4) + b * pow(x, 3) + c * pow( x, 2) + d * pow(x, 1) + e;
    if (true_ans == ans) return 1;
    else return 0;
}

int main(){
    int n, k, count_1 = 0, count_2 = 0, a, b, c, d, e, x;
    long long ans1, ans2;
    int score_1 = 0, score_2 = 0;
    int tmp_1, tmp_2;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a >> b >> c >> d >> e >> x >> ans1 >> ans2;
        tmp_1 = juge(a, b, c, d, e, x, ans1);
        tmp_2 = juge(a, b, c, d, e, x, ans2);
        if (tmp_1 == 1) {
            count_1 ++;
            score_1 ++;
        }
        else if (tmp_1 == 0) count_1 = 0;
        if (tmp_2 == 1) {
            count_2 ++;
            score_2 ++;
        }
        else if (tmp_2 == 0) count_2 = 0; 
        if (count_1 > k) score_1 += count_1 - k;
        if (count_2 > k) score_2 += count_2 - k;
        
    }
    cout << score_1 << " " << score_2 << endl;
    return 0;
}