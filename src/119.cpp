#include <stdio.h>
#include <string.h>

void f(char s[], int l, int r)
{
    // ____qcodep____
    if (l >= r) return;
    char *lch = &s[l];
    char *rch = &s[r];
    char tmp = *rch;
    *rch = *lch;
    *lch = tmp;
    f(s,l+1,r-1);
}

int main(){
    char s[10001];
    scanf("%s", s);
    f(s,0,strlen(s)-1);
    printf("%s",s);
}

