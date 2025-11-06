#include <iostream>
using namespace std;
int n;
int count = 0;

bool col[13] ={false};
bool diag1[25] = {false};
bool diag2[25] = {false};

void backtrack(int row){
    if (row == n){
        count ++;
        return;
    }
    for(int j = 0; j < n; j++){
        int index1 = row-j + n - 1;
        int index2 = row+j;
        if(!col[j] && !diag1[index1] && !diag2 [index2]){
            col[j] = true;
            diag1[index1] = true;
            diag2[index2] = true;

            backtrack(row+1);

            col[j] = false;
            diag1[index1] = false;
            diag2[index2] = false;
        }
    }
}

void solve(){
    cin >> n;
    backtrack(0);
    cout << count << endl;
}

int main(){solve(); return 0;}