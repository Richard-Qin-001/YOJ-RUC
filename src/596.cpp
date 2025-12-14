#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
// ____qcodep____
bool isMatch(int *c1, int *c2)
{
    for (int i = 0; i < 128; i++)
    {
        if (c1[i] != c2[i])
            return false;
    }
    return true;
}

char *checkSubstr(char *s2, char *s1)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len2 > len1)
        return NULL;

    int targetCnt[128] = {0};
    int windowCnt[128] = {0};

    for (int i = 0; i < len2; i++)
    {
        targetCnt[(unsigned char)s2[i]]++;
        windowCnt[(unsigned char)s1[i]]++;
    }
    for (int i = 0; i <= len1 - len2; i++)
    {
        if (isMatch(targetCnt, windowCnt))
        {
            return s1 + i;
        }
        if (i + len2 < len1)
        {
            windowCnt[(unsigned char)s1[i]]--;
            windowCnt[(unsigned char)s1[i + len2]]++;
        }
    }

    return NULL;
}

int main()
{
    char s1[220], s2[220];
    char *pRes = NULL;

    scanf("%s%s", s1, s2);
    pRes = checkSubstr(s1, s2);

    if ( pRes == NULL )
        printf("false\n");
    else{
        pRes[ strlen(s1) ] = '\0';
        printf("%s", pRes);
    }
    return 0;
}