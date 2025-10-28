#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve(){
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        int ni = 0;
        cin >> ni;
        vector<ll> s(ni);
        bool status = true;
        for(int j = 0; j < ni; j++){
            cin >> s[j];
            if(j > 0 && s[j] > s[j-1]) continue;
            else if (j == 0) continue;
            else status = false;
        }
        if (status) cout<< "YES";
        else{
            ll current = s[0];
            cout << current << " ";
            for(int j = 1; j < ni; j++){
                if (s[j] > current){
                    cout << s[j] << " ";
                    current = s[j];
                }
                else break;

            }
        }
        cout << endl;

    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve(); return 0;}