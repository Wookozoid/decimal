#include <stdio.h>
#include "../str_math/str_math.h"
#include "helpers.h"

#define BITS_INT (sizeof(int) * 8)

void int_to_bits(int n, bool *bin_n) {
    long unsigned bits_in_int = BITS_INT;
    int i = 1;
    for (long unsigned j = bits_in_int; j > 0; j--) {
        bin_n[j - 1] = ((i & n) != 0);
        i = i << 1;
    }
}

void decimal_to_bits(s21_decimal value, bool *bin) {
    long unsigned bits_in_int = BITS_INT;
    for (int i = 0; i < (INTS_IN_DECIMAL - 1); i++) {
        int_to_bits(value.bits[i], bin + bits_in_int * i);
    }
}

void print_int_bitwise(int n) {
    long unsigned bits_in_int = BITS_INT;
    bool bin_n[bits_in_int];
    int_to_bits(n, bin_n);
    for (long unsigned j = 0; j < bits_in_int; j++) {
        printf("%d", bin_n[j]);
    }
}

void print_double_bitwise(double d) {
    int *pd = (int *)&d;
    int n = *(pd + 1);
    print_int_bitwise(n);
    printf(" ");
    n = *pd;
    print_int_bitwise(n);
}

void print_decimal_bitwise(s21_decimal value) {
    for (int i = 0; i < (INTS_IN_DECIMAL - 1); i++) {
        print_int_bitwise(value.bits[i]);
        printf(" ");
    }
}

void print_decimal(s21_decimal value) {
    long unsigned bits_in_int = BITS_INT;
    bool bin[bits_in_int * (INTS_IN_DECIMAL - 1)];
    decimal_to_bits(value, bin);
    char str[42] = "0";
    
    for (long unsigned i = bits_in_int * (INTS_IN_DECIMAL - 1); i > 0; i--) {
        if (bin[i - 1]) {
            char pow[42];
            str_powof2(pow, bits_in_int * (INTS_IN_DECIMAL - 1) - i);
            str_sum(str, str, pow);
        }
    }
    printf("%s", str);
}
