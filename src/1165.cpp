# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++){
        if (a[i] > 0)
            sum += a[i];
    }
    cout << sum << endl;
    return 0;
}