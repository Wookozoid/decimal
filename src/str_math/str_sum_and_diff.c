#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "str_math.h"

#define max(a, b) (((a) > (b)) ? (a) : (b))

static int str_add_to_result(char *s, char *str1, char *str2, int amount, bool is_sum, int back_to_digits, int adjust_next_digit) {
    int shift = 0;
    int mult = -(!is_sum) + is_sum;

    for (; shift > -amount; shift--) {
        s[shift] += str1[shift];
        if (str2 != NULL) {
            s[shift] += (str2[shift] - '0') * mult;
        }
        if ((is_sum && s[shift] >= 10 + '0') || (!is_sum && s[shift] < '0')) {
            s[shift] += back_to_digits;
            s[shift - 1] += adjust_next_digit;
        }
    }

    return -shift;
}

static int str_process_fraction(char *s, char *str1, char *str2, int *ii, int *jj, int k) {
    int i = *ii;
    int j = *jj;
    char *point1 = strchr(str1, '.');
    char *point2 = strchr(str2, '.');
    int frac_digits1 = i - (int)((point1 != NULL ? point1 : str1 + i) - str1);
    int frac_digits2 = j - (int)((point2 != NULL ? point2 : str2 + j) - str2);
    char *str;
    int iter_amount;

    if (frac_digits1 > frac_digits2) {
        str = str1;
        iter_amount = frac_digits1 - frac_digits2;
    } else {
        str = str2;
        iter_amount = frac_digits2 - frac_digits1;
        i = j;
    }
    for (int iter = 0; iter < iter_amount; iter++) {
        s[k] = str[i];
        i--;
        k--;
    }
    // int shift = str_add_to_result(s, k, str1, i, str2, j, );
    if (frac_digits1 > frac_digits2)
        *ii = i;
    else
        *jj = i;
    return k;
}

static int str_remove_zeros_at_beginning(char *s) {
    int k = 0;

    while (s[k] == '0')
        k++;

    if (s[k] == '\0' && s[k - 1] == '0')
        k--;

    return k;
}

// static void str_remove_trailing_zeros(char *s) {
//     for (int i = 0; s[i] == '0' || s[i] == '.'; i--)
//         s[i] = '\0';
// }

static int str_positive_sum(char *dst, char *str1, char *str2) {
    int i = strlen(str1) - 1, j = strlen(str2) - 1;
    int s_size = max(i, j) + 3;
    char *s = (char *) calloc(s_size, sizeof(char));
    int k = str_process_fraction(s, str1, str2, &i, &j, s_size - 2);
    int shift = str_add_to_result(s + k, str1 + i, str2 + j, i + j + 1 - (s_size - 3), true, -10, 1);
    k -= shift;

    char *ostr = str2;
    int ostr_len = j;
    if (i > j) {
        ostr = str1;
        ostr_len = i;
    }
    ostr_len -= shift;
    
    shift = str_add_to_result(s + k, ostr + ostr_len, NULL, ostr_len + 1, true, -10, 1);
    k -= shift;
    if (s[k] != 0) {
        s[k] += '0';
    } else
        k++;
    k += str_remove_zeros_at_beginning(s + k);
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
    int k = str_process_fraction(s, str1, str2, &i, &j, s_size - 2);
    int shift = str_add_to_result(s + k, str1 + i, str2 + j, i + j + 1 - (s_size - 3), false, 10, -1);
    k -= shift;
    i -= shift;

    shift = str_add_to_result(s + k, str1 + i, NULL, i + 1, false, 10, -1);
    k -= shift;
    k++;
    k += str_remove_zeros_at_beginning(s + k);
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
    // if (strchr(dst, '.') != NULL)
    //     str_remove_trailing_zeros(dst + res - 1);
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
