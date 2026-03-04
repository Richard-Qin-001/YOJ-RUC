#include <bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cnt = 0;
    while (true)
    {
        char ch;
        cin >> ch;
        if (ch == '@')
        {
            break;
        }
        else if(ch == '('){
            cnt++;
        }
        else if(ch == ')'){
            cnt--;
        }
        if(cnt < 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    if(cnt == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}