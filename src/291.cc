// #include <iostream>
// #include <cstring>

// using namespace std;

// int ch2int(char n){
//     int result = (int)n - 48;
//     return result;
// }

// char int2ch(int n){
//     char result = char(n + 48);
//     return result;
// }

// void strrvs(string& str){
//     size_t len = str.size();
//     for (size_t i =0; i < len/2; i++){
//         swap(str[i], str[len-i-1]);
//     }
// }

// string splus(string a, string b){
//     size_t la = a.size(); 
//     size_t lb = b.size();
//     string result;
//     strrvs(a);
//     strrvs(b);
//     if (la < lb){
//         a.resize(lb);
//         for (size_t i = la; i < lb; i++){
//             a[i] = '0';
//         }
//     }
//     else if (la > lb){
//         b.resize(la);
//         for (size_t i = lb; i < la; i++){
//             b[i] = '0';
//         }
//     }
//     int z = 0;
//     for (size_t i = 0; i < max(la, lb); i++){
//         int x = ch2int(a[i]);
//         int y = ch2int(b[i]);
//         int sum = x + y + z;
//         int k = sum % 10;
//         z = sum / 10;
//         result.push_back(int2ch(k));

//     }
//     if (z != 0){
//         result.push_back(int2ch(z));
//     }
//     strrvs(result);
//     return result;

// }

// string sminus(string a, string b){
//     size_t la = a.size(); 
//     size_t lb = b.size();
//     string result;
//     strrvs(a);
//     strrvs(b);
       
//     if (lb < la) {
//     b.resize(la, '0');
//     }
    
//     int z = 0;
//     for (size_t i = 0; i < max(la, lb); i++){
//         int x = ch2int(a[i]) + z;
//         int y = ch2int(b[i]);
//         z = 0;
//         if (x >= y){
//         result.push_back(int2ch(x - y));
//         } else {
//         result.push_back(int2ch(x + 10 - y));
//         z = -1;
//         }
//     }
//     while (result.size() > 1 && result.back() == '0') {
//         result.pop_back();
//     }
    
//     strrvs(result);
//     if (result.empty() || result == "0") {
//         return "0";
//     }
//     return result;

// }

// int judge(string& a, string& b){
//     size_t la = a.size();
//     size_t lb= b.size();
//     if (la > lb) return 1;
//     else if (la < lb) return 0;
//     else {
//         for (size_t i = 0; i < la; i++){
//             if (ch2int(a[i]) > ch2int(b[i])) return 1;
//             else if (ch2int(a[i]) < ch2int(b[i])) return 0;
//         }
//     }
//     return -1;

// }

// void solve(){
//     char ch;
//     cin >> ch;
//     string in_a, in_b;
//     string a, b;
//     string result;
//     string tmp;
//     cin >> in_a >> in_b;
//     if (ch == '+'){
//         if (in_a[0] != '-' && in_b[0] != '-'){
//             a = in_a;
//             b = in_b;
//             result = splus(a, b);
//         }
//         else if (in_a[0] == '-' && in_b[0] != '-'){
//             a = in_a.substr(1);
//             b = in_b;
//             if (judge(a,b) == 1) {
//                 tmp = sminus(a, b);
//                 result = '-' + tmp;
            
//             }
//             else if(judge(a,b) == 0){
//                 result = sminus(b, a);
//             }
//             else result = '0';
            
//         }
//         else if (in_a[0] != '-' && in_b[0] == '-'){
//             a = in_a;
//             b = in_b.substr(1);
//             if (judge(a,b) == 0) {
//                 tmp = sminus(b, a);
//                 result = '-' + tmp;
//             }
            
            
//             else if(judge(a,b) == 1){
//                 result = sminus(a, b);
//             }
//             else result = '0';
//         }
        
//         else {
//             a = in_a.substr(1);
//             b = in_b.substr(1);
//             tmp = splus(a,b);
//             result = '-' + tmp;

//         }
//     }
//     else{

//         if (in_a[0] != '-' && in_b[0] == '-'){// (+) - (-)
//             a = in_a;
//             b = in_b.substr(1);
//             result = splus(a, b);
//         }
//         else if (in_a[0] != '-' && in_b[0] != '-'){
//             a = in_a;
//             b = in_b;
//             if (judge(a,b) == 1) {
//                 result = sminus(a, b);
//             }
//             else if(judge(a,b) == 0){
//                 tmp = sminus(b, a);
//                 result = '-' + tmp;
//             }
//             else result = '0';
            
//             }
//         else if (in_a[0] == '-' && in_b[0] == '-'){
//             a = in_a.substr(1);
//             b = in_b.substr(1);
//             if (judge(a,b) == 1) {
//                 tmp = sminus(a, b);
//                 result = '-' + tmp;
            
//             }
//             else if(judge(a,b) == 0){
//                 result = sminus(b, a);
//             }
//             else result = '0';
            
//         }
//         else { // (-) - (+)
//             a = in_a.substr(1);
//             b = in_b;
//             tmp = splus(a,b);
//             result = '-' + tmp;
//         }
//     }    
//     cout << result;
// }


// int main(){solve(); return 0;}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class BigInt
{
private:
    string val; //低位在前
    int sign; // 1 for positive -1 for negtive 0 for zero
public:
    BigInt() : val("0"), sign(1) {}
    BigInt(string s){
        if (s.empty()){
            val = "0";
            sign = 1;
            return;
        }
        int start = 0;
        if (s[0] == '+'){
            sign = 1;
            start = 1;
        }
        else if (s[0] == '-'){
            sign = -1;
            start = 1;
        }
        else sign = 1;

        string num_part = s.substr(start);
        size_t first_digit = num_part.find_first_not_of('0');
        if (first_digit == string::npos){
            val = "0";
            sign = 1;
            return;
        }
        val = num_part.substr(first_digit);
        reverse(val.begin(), val.end());
    };
    void print() const{
        if(val == "0"){
            cout << "0" << endl;
            return;
        }
        if (sign == -1)cout << "-";
        string temp_val = val;
        reverse(temp_val.begin(), temp_val.end());
        cout << temp_val << endl;
    };
    BigInt operator+(const BigInt& other) const{
        if (sign == other.sign){
            BigInt result = add_abs(*this, other);
            result.sign = sign;
            return result;
        }
        else{
            int cmp = compare_abs(other);

            if(cmp == 0) return BigInt("0");
            BigInt result;
            if(cmp == 1){
                result = subtract_abs(*this, other);
                result.sign = sign;
            }
            if(cmp == -1){
                result = subtract_abs(other, *this);
                result.sign = other.sign;
            }
            return result;
        }
    }; 
    BigInt operator-(const BigInt& other) const{
        BigInt tmp = other;
        tmp.sign *= -1;
        return *this+tmp;
    };
    ~BigInt();
private:
    int compare_abs(const BigInt& other) const{
        if(val.length() > other.val.length()) return 1;
        if(val.length() < other.val.length()) return -1;

        for(int i = val.length() - 1; i >= 0; i--){
            if(val[i] > other.val[i]) return 1;
            if(val[i] < other.val[i]) return -1;
        }
        return 0;
    }

    static BigInt add_abs(const BigInt& A, const BigInt& B){
        BigInt C;
        C.val.clear();
        int lenA = A.val.length();
        int lenB = B.val.length();
        int max_len = max(lenA, lenB);
        int carry = 0;

        for(int i = 0; i < max_len || carry; i++){
            int a = (i < lenA) ? (A.val[i] - '0') : 0;
            int b = (i < lenB) ? (B.val[i] - '0') : 0;
            int sum = a + b + carry;

            C.val.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
        if (C.val.empty())C.val = "0";
        C.sign = 1;

        return C;
    };
    static BigInt subtract_abs(const BigInt& A, const BigInt& B){
        BigInt C;
        C.val.clear();
        int lenA = A.val.length();
        int lenB = B.val.length();
        int borrow = 0;
        for(int i = 0; i < lenA; i++){
            int a = A.val[i] - '0' - borrow;
            int b = (i < lenB) ? (B.val[i] - '0') : 0;

            if(a < b){
            a += 10;
            borrow = 1;}
            else borrow = 0;
            C.val.push_back((a - b) + '0');
        }
        while (C.val.length() > 1 && C.val.back() == '0') C.val.pop_back();
        {
        }
        if (C.val.empty()) C.val = "0";
        C.sign = 1;
        return C;
    };
};
BigInt::~BigInt()
{
}
void solve(){
    char op_char;
    string a_str, b_str;
    cin >> op_char >> a_str >> b_str;
    BigInt A(a_str), B(b_str);
    BigInt result;
    if(op_char == '-') result = A - B;
    else result = A + B;
    result.print();
}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}