#include <stdlib.h>
#include <string.h>
#include "str_math.h"

int str_powof2(char *dst, int power) {
    int src_size = (power >> 1) + 2;
    char *src = (char *)malloc(src_size * sizeof(char));
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
    strncpy(dst, src + src_size - src_len, src_len);
    dst[src_len] = '\0';
    free(src);
    return src_len;
}
