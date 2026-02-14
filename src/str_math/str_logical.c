#include <string.h>
#include "str_math.h"

bool str_greater(char *str1, char *str2) {
    bool res = false;
    bool c = true;

    int i = 0;
    for (; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (c) {
            c = (str1[i] == str2[i]);
            res = (str1[i] > str2[i]);
        }
    }
    if (str1[i] != str2[i]) {
        res = (str1[i] != '\0');
    }

    return res;
}

bool str_greater_or_equals(char *str1, char *str2) {
    bool res = false;
    bool c = true;

    int i = 0;
    for (; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (c) {
            c = (str1[i] == str2[i]);
            res = (str1[i] >= str2[i]);
        }
    }
    if (str1[i] != str2[i]) {
        res = (str1[i] != '\0');
    }

    return res;
}

bool str_less(char *str1, char *str2) {
    return !str_greater_or_equals(str1, str2);
}

bool str_less_or_equals(char *str1, char *str2) {
    return !str_greater(str1, str2);
}

bool str_equals(char *str1, char *str2) {
    return (strcmp(str1, str2) == 0);
}
