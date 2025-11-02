#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<vector<double>> v;
    for(int i = 0; i< n; i++){
        int id;
        double a, b;
        cin >> id >> a >> b;
        if((b - a) >= 0){
            vector<double> tmp = {(double)id, (b-a)};
            v.push_back(tmp);
        }
    }
    int m = v.size();
    for(auto&c:v) cout << fixed << setprecision(0) <<(int)c[0] << " " << fixed << setprecision(2) << c[1] << endl;
    cout << fixed << setprecision(2) << ((double)m/(double)n) * 100 << "%" << endl;
}
int main(){solve(); return 0;}