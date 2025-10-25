#include <iostream>

using namespace std;

void print_first_lasr_line(const int& n){
    for (int i = 0; i < n - 1; i++) cout << " ";
    for (int i = 0; i < n; i++) cout << "*";
    cout << endl;
}

void print_middle_line(const int&n){
    int n_space = (n-2) * 2 + n;
    cout << "*";
    for (int i = 0; i < n_space; i++) cout << " ";
    cout << "*" << endl;
}

void print_line(const int&n, const int& index){
    int left_space = n - 2 - index;
    for (int i = 0; i < left_space; i++) cout << " ";
    cout << "*";
    int middle_space = n + (index ) * 2;
    for (int i = 0; i < middle_space; i++) cout << " ";
    cout << "*" << endl;
}

void solve(){
    int n;
    cin >> n;
    print_first_lasr_line(n);
    for (int i = 0; i < n-2; i++) print_line(n, i);
    print_middle_line(n);
    for (int i = n-3; i >=0; i--) print_line(n, i);
    print_first_lasr_line(n);
}

int main(void){solve(); return 0;}