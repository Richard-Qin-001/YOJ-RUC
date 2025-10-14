# include <iostream>
using namespace std;

void print(int row, int m){
    int a = 65;
    if (row <= m && row >=1){
        for (int i = row; i >= 1; i--){
            cout << char(a+i);}
        for (int i = 0; i < m - row; i++){
            cout << char(a+i);
        }
        
    }
    else if(row == 0){
        for (int i = 0; i < m; i++){
            cout << char(a+i);
        }
    }
    else {
        for (int i = row; i >= row - m + 1; i--){
            cout << char(a+i);        
    }
    
}
cout << endl;}
int main(){
    int n , m;
    cin >> n >> m;
    for (int j = 0; j < n; j++){
        print(j, m);
    }
    return 0;
}