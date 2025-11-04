#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<char> hex_num = {'0', '1', '2', '3' ,'4' , '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int find_index(char a){
    int index;
    for(int i = 0; i < 16; i++) if(hex_num[i] == a) index = i;
    return index;
}

string create(char first_num, int b){
    string result = "";
    for(int i = 0; i < b; i++){
        int index = i + find_index(first_num);
        result.push_back(hex_num[index % 16]);
    }
    return result;
}

long long power(int base, int exp){
    long long result = 1;
    for(int i = 0; i < exp; i++) result *= base;
    return result;
}

long long transform(string num, int b){
    long long result = 0;
    for(int i = 0; i < b; i++){
        result += find_index(num[i]) * power(16, b-1-i);
    }
    return result;
}

void solve(){
    char a;
    int b, len;
    cin >> a >> b;
    vector<string> list;
    for(int i = find_index(a); i < 16; i++){
        char first_num = hex_num[i];
        string tmp = create(first_num, b);
        list.push_back(tmp);
    }
    long long sum = 0;
    for(auto&c:list){
        sum += transform(c, b);
    }
    cout << sum << endl;

}
int main(){solve(); return 0;}