#include <stdio.h>
#include <string.h>



int operation_c(const char *str, const char *sstr){
    int count  = 0;
    int len = strlen(str);
    int slen = strlen(sstr);
    char tmp[slen + 1];
    for (int i = 0; i < len - slen; i++){
        for (int j = 0; j < slen; j++){
            tmp[j] = str[i+j];
        }
        tmp[slen] = '\0';
        if (strcmp(tmp, sstr) == 0) count++;
    }
    return count;
}

void operation_d(char *str, const char *sstr){
    char *found_pos = strstr(str, sstr);
    if (found_pos == NULL) {
        return; 
    }
    size_t slen = strlen(sstr);
    char *source = found_pos + slen;
    char *destination = found_pos;
    size_t move_len = strlen(source) + 1; 
    memmove(destination, source, move_len);
}

char *find_last_occurrence(char *str, const char *sstr) {
    char *last_pos = NULL;
    char *current_pos = str;   
    while ((current_pos = strstr(current_pos, sstr)) != NULL) {
        last_pos = current_pos;
        current_pos++;
    }
    
    return last_pos;
}

void operation_i(char *str, const char *sstr1, const char *sstr2){
    char *insert_pos = find_last_occurrence(str, sstr1);
    if (insert_pos == NULL) {
        return;
    }

    int len = strlen(str);
    int slen1 = strlen(sstr1);
    int slen2 = strlen(sstr2);
    int index = insert_pos - str;
    int move_len = len - index + 1;
    memmove(str + index + slen2,     // 目标地址
            str + index,            // 源地址（str1 的起始地址）
            move_len);              // 移动的字符数（包括 '\0'）
    memcpy(str + index, sstr2, slen2);
    
}

void operation_r(char *str, const char *sstr1, const char *sstr2){
    int slen1 = strlen(sstr1);
    int slen2 = strlen(sstr2);
    int replace_count = 0;
    char *current_pos = str;
    while (1){
        char *found_pos = strstr(current_pos, sstr1);
        if (found_pos == NULL) {
            break;
        }
        int len = strlen(str);
        int diff_len = slen2 - slen1;
        if (diff_len != 0) {
            char *source = found_pos + slen1;
            char *destination = found_pos + slen2;
            int move_len = len - (found_pos - str) - slen1 + 1;
            memmove(destination, source, move_len);
        }
        memcpy(found_pos, sstr2, slen2);
        current_pos = found_pos + slen2;
    }
}

int main(){
    char str[500];
    if (fgets(str, sizeof(str), stdin) == NULL) return 1;
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
    str[len - 1] = '\0';
    }
    char ch;
    scanf(" %c", &ch);
    if (ch == 'C'){
        char sstr[101];
        scanf("%s", sstr);
        int count =
        operation_c(str, sstr);
        printf("%d", count);
    }
    else if (ch == 'D'){
        char sstr[101];
        scanf("%s", sstr);
        operation_d(str, sstr);
        printf("%s", str);
    }
    else if (ch == 'I'){
        char sstr1[101];
        char sstr2[101];
        scanf("%s", sstr1);
        scanf("%s", sstr2);
        operation_i(str, sstr1, sstr2);
        printf("%s", str);
    }
    else if (ch == 'R'){
        char sstr1[101];
        char sstr2[101];
        scanf("%s", sstr1);
        scanf("%s", sstr2);
        operation_r(str, sstr1, sstr2);
        printf("%s", str);
    }
    return 0;
}