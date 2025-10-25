#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

double A, B, C, D;

double f(double x){
    return A*x*x*x + B*x*x + C*x +D;
}

double find_root_by_bisection(double L, double R){
    if (abs(f(L)) < 1e-6 ) return L;
    while (R - L > 1e-4) {
        double mid = (L + R) / 2.0;
        if (f(L) * f(mid) < 0) {
            R = mid;
        } 
        else {
            L = mid;
        }
    }
    return (L + R)/2.0;
}

void solve(){
    cin >> A >> B >> C >> D;
    vector<double> roots;
    for (int i = -100; i < 100; i++){
        double x1 = (double)i;
        double x2 = (double)i + 1.0;
        double fx1 = f(x1), fx2 = f(x2);
        if (fx1 * fx2 < 0){
            double root = find_root_by_bisection(x1, x2);
            roots.push_back(root);
        }
        else if (abs(fx1) < 1e-6) {
            roots.push_back(x1);
        }
    }
    if (abs(f(100.0)) < 1e-6) {
        roots.push_back(100.0);
    }
    sort(roots.begin(), roots.end());

    vector<double> unique_roots;
    if (!roots.empty()) {
        unique_roots.push_back(roots[0]);
        for (size_t i = 1; i < roots.size(); ++i) {
            if (roots[i] - unique_roots.back() > 0.5) { 
                unique_roots.push_back(roots[i]);
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        cout << fixed << setprecision(2) << unique_roots[i];
        if (i < 2) {
            cout << " ";
        }
    }
    cout << endl;
}
int main(){solve(); return 0;}