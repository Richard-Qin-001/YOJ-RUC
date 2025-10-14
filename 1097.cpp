# include <iostream>
# include <vector>

using namespace std;

int solve(int n, vector<int> v1, vector<int> v2) {
    int count = 0;
    
}

int main(){
    int n;
    cin >> n;
    vector<int> v1(n), v2(n);
    for(int i = 0; i < n; i++) {
        cin >> v1[i];
        v2[i] = 2;
    }
    cout << solve(n, v1, v2) << endl;
    return 0;

}