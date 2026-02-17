#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "str_math.h"

static int str_one_digit_multiplication(char *str, int i, char multiplier, char **dst) {
    char *s = *dst;
    *dst += 1;
    int dst_len = 0;
    s[i + 1] = 0;
    for (; i >= 0; i--) {
        s[i] = 0;
        s[i + 1] += (str[i] - '0') * multiplier;
        if (s[i + 1] >= 10) {
            s[i] += s[i + 1] / 10;
            s[i + 1] %= 10;
        }
        s[i + 1] += '0';
        dst_len++;
    }
    if (s[0] != 0) {
        s[0] += '0';
        *dst -= 1;
        dst_len++;
    }
    return dst_len;
}

static int str_positive_mult(char *dst, char *str, char *multiplier) {
    int i = strlen(str) - 1, j = strlen(multiplier) - 1;
    int s_size = i + j + 3;
    char *s = (char *) calloc(s_size, sizeof(char));
    char *d = (char *) calloc(s_size, sizeof(char));
    char *s0 = s;
    int res = 0;
    int powof10 = 0;
    for (; j >= 0; j--) {
        int s_len = str_one_digit_multiplication(str, i, multiplier[j] - '0', &s);
        for (int k = 0; k < powof10; k++) {
            strcpy(s + s_len + k, "0");
        }
        res = str_sum(d, s, d);
        s = s0;
        powof10++;
    }
    strcpy(dst, d);
    free(s0);
    free(d);
    return res;
}

int str_mult(char *dst, char *str, char *multiplier) {
    int res;
    bool sign1 = (str[0] == '-');
    bool sign2 = (multiplier[0] == '-'); 
    if (sign1 == sign2) {
        res = str_positive_mult(dst, str + sign1, multiplier + sign2);
    } else {
        res = str_positive_mult(dst + 1, str + sign1, multiplier + sign2);
        if (dst[1] == '0') {
            dst[0] = '0';
            dst[1] = '\0';
        } else
            dst[0] = '-';
    }

    return res;
}
