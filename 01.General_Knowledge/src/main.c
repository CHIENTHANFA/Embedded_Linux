#include <stdio.h>
#include "strutils.h"

int main() {
    char s1[100] = "  Hello Devlinux  ";
    char s2[100] = "12345";

    printf("Original: '%s'\n", s1);
    str_trim(s1);
    printf("Trimmed: '%s'\n", s1);

    str_reverse(s1);
    printf("Reversed: '%s'\n", s1);

    printf("String to int: %d\n", str_to_int(s2));
    return 0;
}
