#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "str_math.h"

#define max(a, b) (((a) > (b)) ? (a) : (b))

static void str_remove_trailing_zeros(char *s) {
    for (int i = 0; s[i] == '0' || s[i] == '.'; i--)
        s[i] = '\0';
}

static void str_add_to_result(char *s, char *str1, char *str2, int amount, bool is_sum) {
    char mult = -(!is_sum) + is_sum;

    for (int i = 0; i > -amount; i--) {
        s[i] += str1[i];
        if (str2 != NULL) {
            s[i] += mult * (str2[i] - '0');
        }
        if ((is_sum && s[i] >= 10 + '0') || (!is_sum && s[i] < '0')) {
            s[i] -= 10 * mult;
            s[i - 1] += mult;   
        }
    }

}

static int str_process_fraction(char *s, char *str1, char *str2, int *ii, int *jj, int k, bool is_sum) {
    int i = *ii;
    int j = *jj;
    char *point1 = strchr(str1, '.');
    char *point2 = strchr(str2, '.');
    int frac_digits1 = i - (int)((point1 != NULL ? point1 : str1 + i) - str1);
    int frac_digits2 = j - (int)((point2 != NULL ? point2 : str2 + j) - str2);
    int iter_amount = frac_digits1 - frac_digits2;
    if (frac_digits2 > frac_digits1) {
        char *temp = str1;
        str1 = str2;
        str2 = temp;
        int ti = i;
        i = j;
        j = ti;
        iter_amount = frac_digits2 - frac_digits1;
    }
    str_add_to_result(s + k, str1 + i, NULL, iter_amount, is_sum);
    i -= iter_amount;
    k -= iter_amount;
    int shift = (frac_digits1 + frac_digits2 - iter_amount) >> 1;
    str_add_to_result(s + k, str1 + i, str2 + j, shift, is_sum);
    k -= shift;
    i -= shift;
    j -= shift;
    if (point1 != NULL) {
        i--;
        s[k - 1] = s[k];
        s[k] = '.';
        str_remove_trailing_zeros(s + k + shift + iter_amount);
        k--;
        if (point2 != NULL)
            j--;
    }
    if (frac_digits1 < frac_digits2) {
        *ii = j;
        *jj = i;
    } else {
        *ii = i;
        *jj = j;
    }
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

static int str_positive_sum(char *dst, char *str1, char *str2) {
    int i = strlen(str1) - 1, j = strlen(str2) - 1;
    int s_size = max(i, j) + 3;
    char *s = (char *) calloc(s_size, sizeof(char));
    int k = str_process_fraction(s, str1, str2, &i, &j, s_size - 2, true);
    int shift = i + j + 1 - max(i, j);
    
    str_add_to_result(s + k, str1 + i, str2 + j, shift, true);
    k -= shift;

    char *ostr = str2;
    int ostr_len = j;
    if (i > j) {
        ostr = str1;
        ostr_len = i;
    }
    ostr_len -= shift;
    
    shift = ostr_len + 1;
    str_add_to_result(s + k, ostr + ostr_len, NULL, shift, true);
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
    int k = str_process_fraction(s, str1, str2, &i, &j, s_size - 2, false);
    int shift = i + j + 1 - max(i, j);
    str_add_to_result(s + k, str1 + i, str2 + j, shift, false);
    k -= shift;
    i -= shift;

    shift = i + 1;
    str_add_to_result(s + k, str1 + i, NULL, shift, false);
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
