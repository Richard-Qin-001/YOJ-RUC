#include <stdio.h>

int F(int n) {
    // ____qcodep____
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 1;
    return F(n - 1) + F(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);
    
    printf("%d\n", F(n));
    return 0;
}