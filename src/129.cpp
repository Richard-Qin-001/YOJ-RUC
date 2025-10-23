#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

long long power(long long l, long long n) {
    if (n == 0) return 1;
    long long res = 1;
    for (long long i = 0; i < n; ++i) {
        res *= l;
    }
    return res;
}

map<char, int> mapping(const vector<char>&sys){
    size_t l = sys.size();
    map<char, int> mapsys;
    for (size_t i = 0; i < l; i++){
        mapsys[sys[i]] = i;
    }
    return mapsys;
}

vector<char> transform(const vector<char>&numch, const vector<char>&sys1, const vector<char>&sys2){
    long long l1 = sys1.size();
    long long l2 = sys2.size();
    long long len = numch.size();
    map<char, int> mapsys1 = mapping(sys1);
    map<char, int> mapsys2 = mapping(sys2);
    vector<char> numtarget;
    long long num10 = 0;
    for (long long i = 0; i < len ; i++) num10 += mapsys1.at(numch[len - 1 - i]) * power(l1, i);
    if (num10 == 0) {
        numtarget.push_back(sys2[0]);
        return numtarget;
    }
    while (num10 > 0) {
        long long remainder = num10 % l2;
        numtarget.push_back(sys2[remainder]);
        num10 /= l2;
    } 
    reverse(numtarget.begin(), numtarget.end());
    return numtarget;
}

vector<char> input_vector(){
    string str;
    cin >> str;
    vector<char> result;
    for (auto&c : str)
        result.push_back(c);
    return result;
}

void output_vector(int n, const vector<char>& numtarget){
    cout << "Case #"<< n << ": ";
    for(auto&c : numtarget){
        cout << c;
    }
    cout << endl;

}

void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        vector<char> numch = input_vector(), sys1 = input_vector(), sys2 = input_vector(),
        numtarget = transform(numch, sys1, sys2);
        output_vector(i+1, numtarget);
    }
}
int main(){solve(); return 0;}