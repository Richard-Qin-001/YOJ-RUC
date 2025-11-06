#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool Big_compare(string A, string B){
    int lenA = A.length();
    int lenB = B.length();
    if (lenA > lenB) return true;
    if (lenA < lenB) return false;
    for(int i = lenA - 1; i >= 0; i--){
        if(A[i] > B[i]) return true;
        if(A[i] < B[i]) return false;
    }
    return true;
}

string Big_minus(string A, string B){
    int borrow = 0;
    int lenA = A.length();
    int lenB = B.length();
    string C = "";
    for(int i = 0; i < lenA; i++){
        int a = A[i] - '0' - borrow;
        int b = (i < lenB) ? (B[i] - '0') : 0;
        int diff = a - b;
        if(diff < 0){
            diff += 10;
            borrow = 1;
        }
        else borrow = 0;
        C.push_back(diff + '0');

    }
    while(C.length() > 1 && C.back() == '0'){
        C.pop_back();
    }
    return C;
}

string Big_multiple(string A, int t){
    string C = "";
    int carry = 0;
    int lenA = A.length();
    int index = 0;
    for(int i = 0; i < lenA; i++){
        int a = A[i] - '0';
        int product = a * t + carry;
        carry = product / 10;
        int digit = product % 10;
        C.push_back(digit + '0');
    }
    while (carry)
    {
        int digit = carry % 10;
        carry /= 10;
        C.push_back(digit + '0');
    }
    return C;

}

void solve(){
    string A, B;
    cin >> A >> B;
    reverse(A.begin(), A.end()), reverse(B.begin(), B.end());
    int t = 1;
    while (Big_compare(A, Big_multiple(B, t))) t++;
    t--;
    {
        string remender = Big_minus(A, Big_multiple(B, t));
        reverse(remender.begin(), remender.end());
        cout << remender << endl;
    }
    
}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}