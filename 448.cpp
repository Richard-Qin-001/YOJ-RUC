#include <cstdio>
#include <cstring>

int main() {
    char num[102]; // 预留空间，支持100位整数
    char str[102];
    scanf("%101s", num);           // 读入大整数
    getchar();                     // 读取并丢弃换行符
    fgets(str, 102, stdin);        // 读入带空格的字符串
    // 去除字符串末尾的换行符
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    printf("%s\n", num);
    printf("%s\n", str);
    return 0;
}