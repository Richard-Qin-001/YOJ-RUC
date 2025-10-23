#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstring>
using namespace std;

int replaceStr(char A[ ], const char B[ ], const char C[ ])
{
//补充代码，完成此函数
// ____qcodep____
char *pB = strstr(A, B);
size_t lenB = strlen(B);
size_t lenC = strlen(C);

if (pB != NULL){
    size_t indexB = pB - A;
    if (lenC == lenB) strncpy(pB, C, lenC);
    else if (lenC < lenB){
        memmove(pB+lenC, pB+lenB, strlen(pB + lenB) + 1);
        strncpy(pB, C, lenC);
    }
    else{
        memmove(pB+lenC, pB+lenB, strlen(pB + lenB) + 1);
        strncpy(pB, C, lenC);
    }
    return 1;
    
}
else{
    strcat(A, C);
    return 0;
}

}



int main()
{
    char str1[110], str2[110], str3[110];
    int nRes;

    cin.getline(str1, 100);
    cin.getline(str2, 100);
    cin.getline(str3, 100);

    nRes = replaceStr(str1, str2, str3);
    printf("%d\n", nRes);
    printf("%s", str1);
    return 0;

}

