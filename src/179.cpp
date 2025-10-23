// # include <iostream>

// using namespace std;

// void print_fist_last_line(int n){
//     for (int i = 1; i < n; i++){
//         cout << " ";
//     }
//     for (int i = 0; i < n; i++){
//         cout << "*";
//     }
//     cout << endl;

// }

// void print_line(int n){
//     int space_1 = n - 1, space_2 = n;
//     for (int i = 1; i < n - 1; i++){
//         for (int j = 1; j <= space_1; j++) {
//             cout << " ";
//             space_1--;
//         }
//         cout << "*" ;
//         for (int j = 1; j <= space_2; j++){
//             cout << " ";
//             space_2 += 2;
//         }
//         cout << "*" << endl;
//     }
//     for (int i = 1; i < n - 1; i++){
//         for (int j = 1; j <= space_1; j++) {
//             cout << " ";
//             space_1++;
//         }
//         cout << "*" ;
//         for (int j = 1; j <= space_2; j++){
//             cout << " ";
//             space_2 -= 2;
//         }
//         cout << "*" << endl;
//     }

// }

// void solve(int n){
//     print_fist_last_line(n);
//     print_line(n);
//     print_fist_last_line(n);
   
   
// }
// int main(){
//     int n;
//     cin >> n;
//     solve(n);
//     return 0;
// }

