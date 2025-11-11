#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "strutils.h"

void str_reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}

void str_trim(char *str) {
    // Bỏ khoảng trắng đầu
    char *start = str;
    while (isspace((unsigned char)*start)) start++;
    
    // Bỏ khoảng trắng cuối
    char *end = str + strlen(str) - 1;
    while (end > start && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';

    // Dịch chuỗi về đầu
    memmove(str, start, end - start + 2);
}

int str_to_int(const char *str) {
    int val = 0;
    while (*str) {
        if (!isdigit((unsigned char)*str))
            return -1; // Lỗi nếu gặp ký tự không phải số
        val = val * 10 + (*str - '0');
        str++;
    }
    return val;
}
