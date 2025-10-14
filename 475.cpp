#include <iostream>
#include <vector>

using namespace std;



int main(){
    vector<int> v1(30), v2(30);
    int len1 = 0, len2 = 0;
    while (1){
        int tmp;
        cin >> tmp;
        if (tmp == -1) break;
        v1[len1] = tmp;
        len1++;
    }
    // v1.resize(len1);
    cout << len1 << endl;
    while (1){
        int tmp;
        cin >> tmp;
        if (tmp == -1) break;
        v2[len2] = tmp;
        len2++;
    }
    // v2.resize(len2);
    cout << len2 << endl;
    int m = min(len1, len2);
    int diff = 0;
    for (int i = 0; i < m; i++){
        // cout << v1[i] << ' ' <<v2[i] << endl;
        if (v1[i] != v2[i]){
            diff = v1[i] - v2[i];
            break;
        }
    }
    if (len1 == len2 && diff == 0){
        cout << diff;
    }
    else if (diff == 0){
        cout << "Not Comparable";
    }
    else cout << diff;


    return 0;
}