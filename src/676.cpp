#include <stdio.h>

void word(char *s){
// ____qcodep____
int arry[26] = {0};
int i = 0;
while (s[i] != '\0'){
    arry[s[i] - 97]++;
    i++;
}
int maxn = 0, minn = 100;
for(int i = 0; i < 26; i++){
    if(arry[i] > 0){
        if(arry[i] > maxn) maxn = arry[i];
    if(arry[i] < minn) minn = arry[i];
    }
}
int prime_list[101];
for(int i = 2; i <= 100; i++)prime_list[i] = 1;
prime_list[0] = prime_list[1] = 0;
for(int i = 2; i <= 100; i++){
    if(prime_list[i] == 1){
        for(int j = i * 2; j <= 100; j += i){
            prime_list[j] = 0;
        }
    }
}
int diff = maxn - minn;
if(prime_list[diff] == 1){
    printf("%s\n", "Lucky Word");
    printf("%d\n", diff);
}
else{
    printf("%s\n", "No Answer");
    printf("%d\n", 0);
}

}
int main(void){
    char s[102];
    scanf("%s",s);
    word(s);
    return 0;
}
