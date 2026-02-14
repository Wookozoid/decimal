#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "s21_decimal.h"
#include "helpers/helpers.h"
#include "decimal/decimal.h"
#include "str_math/str_math.h"

#define BITS_INT (sizeof(int) * 8)

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int error = 0;
    if (decimal_get_sign(value_1) == decimal_get_sign(value_2)) {
        decimal_positive_sum(value_1, value_2, result);
    }
    return error;
}

int main() {
    s21_decimal v = {0};
    v.bits[1] = 5;
    v.bits[2] = INT_MAX;
    s21_decimal v2 = {0};
    v2.bits[0] = INT_MAX;
    v2.bits[1] = 205;
    v2.bits[2] = INT_MAX - 3;
    print_decimal(v);
    printf("\n");
    print_decimal(v2);
    printf("\n");
    s21_decimal add_result;
    s21_add(v, v2, &add_result);
    printf("=\n");
    print_decimal(add_result);
    // char s1[42] = "124152", s2[42] = "1";
    // int a = str_mult(s1, s2, s1);
    // printf("<%d> %s", a, s1);

    printf("\n");
    return 0;
}