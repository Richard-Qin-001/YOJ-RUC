# include <iostream>
# include <iomanip>
using namespace std;

double solve1(int price1, int price2, int num1, int num2){
    int num;
    num = num1 + num2;
    double pay;
    pay = price1 * num1 + price2 * num2;
    if (num <2){
        return pay;
    }
    else if (num == 2){
        return pay * 0.9;
    }
    else if (num == 3 || num == 4){
        return pay * 0.8;
    }
    else{
        return pay * 0.7;
    }
}
double solve2(int price1, int price2, int num1, int num2){
    int sum, n;
    sum = price1 * num1 + price2 * num2;
    n = sum / 500;
    return sum - n * 100;
}
int main(){
    int price1, price2, num1, num2;
    cin >> price1 >> price2 >> num1 >> num2;
    double ans1, ans2;
    ans1 = solve1(price1, price2, num1, num2);
    ans2 = solve2(price1, price2, num1, num2);
    cout << fixed << setprecision(1);

    if (ans1 <= ans2){
        cout << 1 << ' ' << ans1 << endl;
    }
    else{
        cout << 2 << ' ' << ans2 << endl;
    }
    return 0;
}
