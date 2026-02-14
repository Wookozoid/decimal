#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "str_math.h"

#define max(a, b) (((a) > (b)) ? (a) : (b))

static int str_positive_sum(char *dst, char *str1, char *str2) {
    int i = strlen(str1) - 1, j = strlen(str2) - 1;
    int s_size = max(i, j) + 3;
    char *s = (char *) calloc(s_size, sizeof(char));
    int k = s_size - 2;
    for (; i >= 0 && j >= 0; i--, j--) {
        s[k] += str1[i] + str2[j] - '0';
        if (s[k] >= 10 + '0') {
            s[k] -= 10 ;
            s[k - 1] += 1;
        }
        k--;
    }
    char *ostr;
    int ostr_len;
    if (i > j) {
        ostr = str1;
        ostr_len = i;
    } else {
        ostr = str2;
        ostr_len = j;
    }
    for (i = ostr_len; i >= 0; i--) {
        s[k] += ostr[i];
        if (s[k] >= 10 + '0') {
            s[k] -= 10;
            s[k - 1] += 1;
        }
        k--;
    }
    if (s[k] != 0) {
        s[k] += '0';
        k--;
    }
    k++;
    strcpy(dst, s + k);
    free(s);
    return s_size - k - 1;
}

static int str_positive_difference(char *dst, char *str1, char *str2) {
    bool negative = false;
    if (str_less(str1, str2)) {
        char * temp = str1;
        str1 = str2;
        str2 = temp;
        negative = true;
    }
    int i = strlen(str1) - 1, j = strlen(str2) - 1;
    int s_size = max(i, j) + 3;
    char *s = (char *) calloc(s_size, sizeof(char));
    int k = s_size - 2;
    for (; i >= 0 && j >= 0; i--, j--) {
        s[k] += str1[i] - str2[j] + '0';
        if (s[k] < '0') {
            s[k] += 10 ;
            s[k - 1] -= 1;
        }
        k--;
    }
    for (; i >= 0; i--) {
        s[k] += str1[i];
        if (s[k] < '0') {
            s[k] += 10;
            s[k - 1] -= 1;
        }
        k--;
    }
    while (s[k + 1] == '0') {
        k++;
    }
    k += 1;
    if (s[k] == '\0' && s[k - 1] == '0')
        k -= 1;
    strcpy(dst + negative, s + k);
    if (negative)
        dst[0] = '-';
    free(s);
    return s_size - k + negative - 1;
}

static int str_handle_sum_or_difference(char *dst, char *str1, char *str2, bool is_sum) {
    int res;
    bool sign1 = (str1[0] == '-');
    bool sign2 = (str2[0] == '-'); 
    if ((sign1 == sign2) == is_sum) {
        res = str_positive_sum(dst + sign1, str1 + sign1, str2 + sign2);
        if (sign1)
            dst[0] = '-';
    } else {
        if (sign1) {
            char *temp = str1;
            str1 = str2;
            str2 = temp;
            bool t = sign1;
            sign1 = sign2;
            sign2 = t;
        }
        res = str_positive_difference(dst, str1 + sign1, str2 + sign2);
    }
    return res;
}

int str_sum(char *dst, char *str1, char *str2) {
    int res = str_handle_sum_or_difference(dst, str1, str2, true);
    
    return res;
}

int str_diff(char *dst, char *str1, char *str2) {
    int res = str_handle_sum_or_difference(dst, str1, str2, false);
    
    return res;
}
