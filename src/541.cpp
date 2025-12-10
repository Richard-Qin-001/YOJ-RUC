#include<stdio.h>
#include<string.h>

char parseCmd(char *s, char *str1, char *str2)
{
// ____qcodep____ 
    char *pos = s;
    char cmd = *pos;
    pos += 2;
    while (*pos != ' ' && *pos != '\0')
    {
        *str1++ = *pos++;
    }
    *str1 = '\0';
    if (*pos == ' ')
    {
        pos++;
        while (*pos != '\0')
        {
            *str2++ = *pos++;
        }
    }
    *str2 = '\0';
    return cmd;
    
}

// ____qcodep____
int countStr(char *s, char *str1){
    int total = 0;
    char *pos = s;
    int slen = strlen(str1);
    while ((pos = strstr(pos, str1)) != NULL)
    {
        total++;
        pos += slen;
    }
    return total;
}

void deleteStr(char *s, char *pstr){
    char temp[500];
    char *match = strstr(s, pstr);
    int p_len = strlen(pstr);

    if (match == NULL || p_len == 0)
        return;
    strncpy(temp, s, match - s);
    temp[match - s] = '\0';
    strcat(temp, match + p_len);
    strcpy(s, temp);
}

void insertStr(char *s, char *str1, char *str2){
    char temp[500];
    char *match = NULL;
    char *__match = s;
    int slen1 = strlen(str1);
    int slen2 = strlen(str2);
    while ((__match = strstr(__match, str1)) != NULL)
    {
        match = __match;
        __match += slen1;
    }
    if(match == NULL)return;
    int len1 = match - s;
    strncpy(temp, s, len1);
    temp[len1] = '\0';
    strcat(temp, str2);
    strcat(temp, match);
    strcpy(s, temp);
}

char * replaceStr(char *s, char *str1, char *str2){
    char temp[500];
    char *pos = s;
    char *tpos = temp;
    int slen1 = strlen(str1), slen2 = strlen(str2);

    while (*pos != '\0')
    {
        char *match = strstr(pos, str1);
        if (match != NULL)
        {
            while (pos < match)
            {
                *tpos++ = *pos++;
            }
            pos += slen1;
            for (int i = 0; i < slen2; ++i)
                *tpos++ = str2[i];
        }
        else
        {
            while (*pos != '\0')
            *tpos++ = *pos++;
        }
    }
    *tpos = '\0';
    strcpy(s, temp);
    return s;
}

int main()
{
	char s[500], cmdStr[500], str1[500], str2[500], cmd;
	char *pStr1, *pStr2;

    gets(s);
	gets(cmdStr);
    pStr1 = str1;
    pStr2 = str2;

    cmd = parseCmd(cmdStr, pStr1, pStr2);

    switch ( cmd )
    {
    case 'C':
        printf("%d\n", countStr(s, pStr1));
        break;
    case 'D':
        deleteStr(s, pStr1);
        printf("%s\n", s);
        break;
    case 'I':
        insertStr(s, pStr1, pStr2);
        printf("%s\n", s);
        break;
    case 'R':
        printf("%s\n", replaceStr(s, pStr1, pStr2));
        break;
    }
    return 0;
}
