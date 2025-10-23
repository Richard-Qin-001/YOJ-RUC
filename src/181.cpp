// # include <iostream>

// int solve(int a, int b, int n){
//     if (n == 1 || n == 2){
//         return 1;
//     }
//     else{
//         return ((a * solve(a, b, n - 1) + b * solve(a, b, n - 2)) % 7);
//     }
// }

// int main(){
//     int a, b, n;
//     std::cin >> a >> b >> n;
//     std::cout << solve(a, b, n) << std::endl;
//     return 0;
// }
