#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

void print_vector(vector<long long> v){
    int len = v.size();
    for (int i = 0; i < len; i++){
        cout << v[i];
        if (i != len - 1){
            cout << " ";
        }
    }
}

long long power_of_10(int exp) {
    long long res = 1;
    for (int i = 0; i < exp; ++i) {
        res *= 10;
    }
    return res;
}

int main(){
    char str[25];
    if (scanf("%s", str) != 1) return 0;
    int len = strlen(str);
    
    long long n1, n2, n3, n4;
    long long sum = 0;
    
    vector<long long> v;
    
    for (int i = 0; i < len - 3; i++){ 
        for(int j = i + 1; j < len - 2; j++){ 
            for (int k = j + 1; k < len - 1; k++){
                
                n1 = 0;
                n2 = 0;
                n3 = 0;
                n4 = 0;
                
                int d1 = i + 1;
                int d2 = j - i;
                int d3 = k - j;
                int d4 = len - k - 1;
                
                for (int a = 0; a < d1; a++){
                    int t1 = (int)str[a] - '0';
                    long long t2 = power_of_10(d1 - a - 1);
                    n1 += t1 * t2;
                }
                
                for (int b = d1; b < d1 + d2; b++){
                    int t1 = (int)str[b] - '0';
                    long long t2 = power_of_10(d1 + d2 - b - 1);
                    n2 += t1 * t2;
                }
                
                for (int c = d1 + d2; c < d1 + d2 + d3; c++){
                    int t1 = (int)str[c] - '0';
                    long long t2 = power_of_10(d1 + d2 + d3 - c - 1);
                    n3 += t1 * t2;
                }
                
                for (int d = d1 + d2 + d3 ; d < d1 + d2 + d3 + d4; d++){
                    int t1 = (int)str[d] - '0';
                    long long t2 = power_of_10(d1 + d2 + d3 + d4 - d - 1);
                    n4 += t1 * t2;
                }
                
                sum = n1 + n2 + n3 + n4;

                v.push_back(sum);
            }
        }
    }
    
    sort(v.begin(), v.end(), greater<long long>());
    print_vector(v);

    return 0;
}