#include <stdbool.h>
#include "decimal.h"

typedef union {
    int i;
    struct {
        int empty1 : 16;
        int exp : 8;
        int empty2 : 7;
        int sign : 1;
    } s;
} third_int;

char decimal_get_sign(s21_decimal value) {
    char res;
    third_int ti;
    ti.i = value.bits[INTS_IN_DECIMAL - 1];
    if (ti.s.sign == -1) 
        res = '-';
    else
        res = '+';

    return res;
}

void decimal_positive_sum(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    bool overflow = false, old_overflow = false;
    int *val1 = value_1.bits, *val2 = value_2.bits;
    int bit_and[INTS_IN_DECIMAL];
    bool bit_and_empty = true;
    int bit_xor_i, bit_and_i;
    do {
        bit_and_empty = true;
        for (int i = INTS_IN_DECIMAL - 2; i >= 0; i--) {
            bit_xor_i = val1[i] ^ val2[i];
            bit_and_i = val1[i] & val2[i];
            overflow = (bit_and_i < 0);
            bit_and_i <<= 1;
            bit_and_i += old_overflow;

            old_overflow = overflow;
            bit_and_empty = bit_and_empty && (bit_and_i == 0);
            result->bits[i] = bit_xor_i;
            bit_and[i] = bit_and_i;
        }
        val1 = result->bits;
        val2 = bit_and;
    } while (!bit_and_empty);
}
