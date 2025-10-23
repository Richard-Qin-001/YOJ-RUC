#include <string.h>
#include <stdio.h> 

void my_strrev(char *str) {
    int len = strlen(str);
    char *start = str;
    char *end = str + len - 1;
    char temp;

    while (end > start) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    char num[5];
    scanf("%s", num);
    my_strrev(num);
    
    for (int i = 0; i < strlen(num); i++)
    printf("%c,", num[i]);
    printf("%i", strlen(num));
    return 0;
}