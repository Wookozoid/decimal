#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "str_math.h"

static void* safe_realloc(void* ptr, size_t new_size) {
    void *temp_ptr = calloc(new_size, sizeof(ptr[0]));
    void *res;
    
    if (temp_ptr == NULL && new_size > 0) {
        fprintf(stderr, "ERROR: realloc failed for size %zu\n", new_size);
        res = ptr;
    } else {
        memcpy(temp_ptr, ptr, strlen(ptr) + 1);
        res = temp_ptr;
        free(ptr);
    }

    return res;
}

int str_pow(char *dst, char *str, char *power) {
    int res = 0;

    int str_len = strlen(str);
    char *s = (char *) calloc(2, sizeof(char));
    s[0] = '1';

    int power_len = strlen(power);
    char *pow = (char *) calloc((power_len + 1), sizeof(char));
    pow[0] = '0';

    for (;str_less(pow, power);str_sum(pow, pow, "1")) {
        s = safe_realloc(s, res + str_len + 2);
        res = str_mult(s, s, str);
    }

    strcpy(dst, s);
    free(pow);
    free(s);
    return res;
}

int str_powof2(char *dst, int power) {
    int src_size = (power >> 1) + 2;
    char *src = (char *) calloc(src_size, sizeof(char));
    int src_len = 1;
    src[src_size - 1] = '1';
    for (int i = 0; i < power; i++) {
        char *mult_src = src + src_size - src_len;
        mult_src[-1] = '0';
        for (int j = 0; j < src_len; j++) {
            mult_src[j] -= '0'; 
            mult_src[j] <<= 1;
            mult_src[j - 1] += (mult_src[j] >= 10);
            mult_src[j] = mult_src[j] % 10;
            mult_src[j] += '0';
        }
        if (mult_src[-1] != '0')
            src_len++;
    }
    strcpy(dst, src + src_size - src_len);
    dst[src_len] = '\0';
    free(src);
    return src_len;
}
