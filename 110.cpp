#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    char str[1001];
    scanf("%s", str);
    int len = strlen(str);
    int state = 0;
    for (int i = 0; i <= len/2; i++){
        if (str[i] != str[len-i-1]){
            state = 1;
            break;
        }
    }
    if (state == 0){
        printf("%s", "Yes");
    }
    else printf("%s", "No");
    return 0;
}