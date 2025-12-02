#include<stdio.h>
#include<string.h>

char parseCmd(char *s, char *str1, char *str2)
{
// ____qcodep____    
}

// ____qcodep____
int countStr(char *s, char *str1){
    
}

int deleteStr(char *s, char *pstr){

}

int insertStr(char *s, char *str1, char *str2){

}

int replaceStr(char *s, char *str1, char *str2){
    
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
