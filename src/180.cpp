# include <iostream>
# include <cmath>
# include <iomanip>
#include <numbers>

using namespace std;
const double M_PI = std::numbers::pi;

long double normalize_x(long double x) {
    x = fmod(x, 2.0 * M_PI); 
    if (x < 0) {
        x += 2.0 * M_PI;
    }
    if (x > M_PI) {
        x -= 2.0 * M_PI;
    }
    return x;
}

long double calculate_sin(long double x, long double epsilon){
    long double term = x;
    long double sum = 0;
    long long n = 1;
    while (abs(term) >= epsilon){       
        sum += term;
        term = -term * x * x / ((2.0 * n) * (2.0 * n + 1.0));
        n++;
    }
    return sum;
}

long double calculate_cos(long double x, long double epsilon){
    long double term = 1.0;
    long double sum = 0;
    long long n = 1;
    while (abs(term) >= epsilon){
        sum += term;
        term = -term * x * x / ((2.0 * n) * (2.0 * n - 1.0));
        n++;
    }
    return sum;
}

int main(){
    long double x, epsilon;
    cin >> x >> epsilon;
    if (x >= 30){
        x = normalize_x(x);
    }
    
    long double sin_approx = calculate_sin(x, epsilon);
    long double cos_approx = calculate_cos(x, epsilon);
    cout << sin_approx << endl;
    cout << cos_approx << endl;
    return 0;

}