#include <bits/stdc++.h>
using namespace std;

class BigInt{
    using ll = long long;
private:
    static const int BASE = 10000;
    static const int WIDTH = 4;
    vector<int> s;
public:
    BigInt(int num = 0){*this = num;}
    BigInt(const string& str){
        s.clear();
        int len = str.length();
        for(int i = len; i > 0; i -= WIDTH){
            int end = i;
            int start = max(0, i - WIDTH);
            int x = stoi(str.substr(start, end - start));
            s.push_back(x);
        }
    }
    BigInt& operator=(int num){
        s.clear();
        do{
            s.push_back(num % BASE);
            num /= BASE;
        }while (num > 0);
        return *this;
    }
    BigInt operator+(const BigInt&b)const{
        BigInt c;
        c.s.clear();
        c.s.reserve(max(s.size(), b.s.size()) + 1);
        int g = 0;
        size_t s_len = s.size(), b_s_len = b.s.size();
        for(size_t i = 0; i < s_len || i < b_s_len || g; ++i){
            int x = g;
            if(i < s_len) x += s[i];
            if(i < b_s_len) x += b.s[i];
            c.s.emplace_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }
    BigInt& operator+=(const BigInt& b){
        *this = *this + b;
        return *this;
    }
    BigInt operator*(int b)const{
        BigInt c;
        c.s.clear();
        c.s.reserve(s.size() * b + 1);
        ll g = 0;
        int s_len = s.size();
        for(size_t i = 0; i < s_len || g; ++i){
            ll x = g;
            if(i < s_len) x += 1LL * s[i] * b;
            c.s.emplace_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }
    friend ostream& operator<<(ostream& out, const BigInt& x){
    if (x.s.empty()){
        out << 0;
        return out;
    }
    out << x.s.back();
    for(int i = x.s.size() - 2; i >= 0; --i)out << setw(WIDTH) << setfill('0') << x.s[i];
    return out;
}
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    BigInt F = 1, S = 1;
    for(int i = 2; i <= n; ++i){
        BigInt i2 = BigInt(i) * i;
        F = i2 + S;
        S += F;
    }
    cout << F << endl;
    return 0;
}