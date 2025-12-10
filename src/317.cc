#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string str;
    getline(cin, str);
    int len = str.length();
    vector<ll> nums;
    int i = 0;
    while (str[i] != '\0')
    {
        if(str[i] >= '0' && str[i] <= '9'){
            int j = i + 1;
            while (str[j] >= '0' && str[j] <= '9')
            {
                j++;
            }
            ll num = 0;
            for(int k = i; k < j; k++){
                num = num * 10 + str[k] - '0';
            }
            nums.emplace_back(num);
            i = j;
            continue;
        }
        i++;
    }
    ll sum = 0;
    for(auto&n:nums)sum += n;
    cout << sum << endl;
    return 0;
}