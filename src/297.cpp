#include <stdio.h>

int main() {
    const char *weekdays[] = {
        "","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
    };

    int d1, d2;
    scanf("%d %d", &d1, &d2);
    int next_d1 = (d1 % 7) + 1;
    int prev_d2 = (d2 - 2 + 7) % 7 + 1;

    printf("%s\n", weekdays[next_d1]);
    
    printf("%s\n", weekdays[prev_d2]);

    return 0;
}