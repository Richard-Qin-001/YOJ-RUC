#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
// ____qcodep____
#include <map>

char *checkSubstr(char *s2, char *s1)
{
    int len1 = strlen(s1), len2 = strlen(s2);
    map<char, int> s2map;
    for (int i = 0; i < len2; ++i)
        s2map[s2[i]]++;
    for (int i = 0; i <= len1 - len2; ++i)
    {
        map<char, int> s1map;
        for (int j = i; j < i + len2; ++j)
            s1map[s1[j]]++;
        bool status = true;
        for (auto &p : s2map)
        {
            if (s1map[p.first] != p.second)
            {
                status = false;
                break;
            }
        }
        if (status)
            return s1 + i;
    }
    return NULL;
}

int main()
{
    char s1[220], s2[220];
    char *pRes = NULL;

    scanf("%s%s", s1, s2);
    pRes = checkSubstr(s1, s2);

    if (pRes == NULL)
        printf("false\n");
    else
    {
        pRes[strlen(s1)] = '\0';
        printf("%s", pRes);
    }
    return 0;
}