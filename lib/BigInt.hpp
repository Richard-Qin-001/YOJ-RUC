#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

class BigInt{
    using ll = long long;
private:
    static const int BASE = 10000;
    static const int WIDTH = 4;
    std::vector<int> s;
public:
    BigInt(int num = 0){*this = num;}
    BigInt(const std::string& str){
        s.clear();
        int len = str.length();
        for(int i = len; i > 0; i -= WIDTH){
            int end = i;
            int start = std::max(0, i - WIDTH);
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
        c.s.reserve(std::max(s.size(), b.s.size()) + 1);
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
        ll g = 0;
        int s_len = s.size();
        for(size_t i = 0; i < s_len || g; ++i){
            ll x = g;
            if(i < s_len) x += 1LL * s[i] * b;
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }
    BigInt operator*(const BigInt&b)const{
        BigInt c;
        c.s.assign(s.size() + b.s.size(), 0);
        size_t s_len = s.size(), b_s_len = b.s.size();
        for(size_t i = 0; i < s_len; ++i){
            ll carry = 0;
            for(size_t j = 0; j < b_s_len; ++j){
                ll tmp = c.s[i + j] + 1LL * s[i] * (j < b_s_len ? b.s[j] : 0) + carry;
                c.s[i + j] = tmp % BASE;
                carry = tmp / BASE;
            }
        }
        while (c.s.size() > 1 && c.s.back() == 0)c.s.pop_back();
        return c;
    }
    BigInt operator/(int b) const {
        BigInt c;
        c.s.resize(s.size());
        ll rem = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            ll cur = s[i] + rem * BASE;
            c.s[i] = cur / b;
            rem = cur % b;
        }
        while (c.s.size() > 1 && c.s.back() == 0) c.s.pop_back();
        return c;
    }

    int operator%(int b) const {
        ll rem = 0;
        for (int i = s.size() - 1; i >= 0; --i)
            rem = (rem * BASE + s[i]) % b;
        return rem;
    }
    bool operator<(const BigInt& b) const{
        if(s.size() != b.s.size()) return s.size() < b.s.size();
        for(int i = s.size() - 1; i >=0; --i){
            if(s[i] != b.s[i]) return s[i] < b.s[i];
        }
        return false;
    }
    bool operator==(const BigInt&b) const{
        if(s.size() != b.s.size()) return false;
        for(int i = s.size() - 1; i >= 0; --i)if(s[i] != b.s[i])return false;
        return true;
    }
    bool operator>(const BigInt&b) const{
        if(!(*this < b) && !(*this == b))return true;
        return false;
    }
    bool operator!=(const BigInt&b)const{
        if(!(*this == b))return true;
        return false;
    }
    bool operator>=(const BigInt&b)const{
        if(!(*this < b))return true;
        return false;
    }
    bool operator<=(const BigInt&b) const{
        if(!(*this > b))return true;
        return false;
    }
    friend std::ostream& operator<<(std::ostream& out, const BigInt& x){
    if (x.s.empty()){
        out << 0;
        return out;
    }
    out << x.s.back();
    for(int i = x.s.size() - 2; i >= 0; --i)out << std::setw(WIDTH) << std::setfill('0') << x.s[i];
    return out;
    }
    friend std::istream& operator>>(std::istream& in, BigInt&x){
        std::string str;
        in >> str;
        x = BigInt(str);
        return in;
    }
    
    static std::vector<ll> karatsubaMultiply(const std::vector<int>& a, const std::vector<int>& b) {
        int n = a.size(), m = b.size();
        if (n < 32 || m < 32) {
            std::vector<ll> res(n + m);
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    res[i + j] += 1LL * a[i] * b[j];
            return res;
        }

        int half = n / 2;
        std::vector<int> a0(a.begin(), a.begin() + half);
        std::vector<int> a1(a.begin() + half, a.end());
        std::vector<int> b0(b.begin(), b.begin() + std::min<int>(b.size(), half));
        std::vector<int> b1(b.begin() + std::min<int>(b.size(), half), b.end());

        auto z0 = karatsubaMultiply(a0, b0);
        auto z2 = karatsubaMultiply(a1, b1);

        std::vector<int> a0_copy = a0, a1_copy = a1;
        std::vector<int> b0_copy = b0, b1_copy = b1;

        int len = std::max(a0_copy.size(), a1_copy.size());
        a0_copy.resize(len);
        a1_copy.resize(len);
        for (int i = 0; i < len; ++i) a1_copy[i] += a0_copy[i];

        len = std::max(b0_copy.size(), b1_copy.size());
        b0_copy.resize(len);
        b1_copy.resize(len);
        for (int i = 0; i < len; ++i) b1_copy[i] += b0_copy[i];

        auto z1 = karatsubaMultiply(a1_copy, b1_copy);
        for (int i = 0; i < z0.size(); ++i) z1[i] -= z0[i];
        for (int i = 0; i < z2.size(); ++i) z1[i] -= z2[i];

        std::vector<ll> res(n + m);
        for (int i = 0; i < z0.size(); ++i) res[i] += z0[i];
        for (int i = 0; i < z1.size(); ++i) res[i + half] += z1[i];
        for (int i = 0; i < z2.size(); ++i) res[i + 2 * half] += z2[i];
        return res;
    }
    BigInt operator*(const BigInt& b) const {
        BigInt res;
        std::vector<ll> raw = karatsubaMultiply(this->s, b.s);
        res.s.resize(raw.size());
        ll carry = 0;
        for (size_t i = 0; i < raw.size(); ++i) {
            ll cur = raw[i] + carry;
            res.s[i] = cur % BASE;
            carry = cur / BASE;
        }
        while (carry > 0) {
            res.s.push_back(carry % BASE);
            carry /= BASE;
        }
        while (res.s.size() > 1 && res.s.back() == 0) res.s.pop_back();
        return res;
    }

};
