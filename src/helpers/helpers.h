#ifndef LIB_HELPERS
#define LIB_HELPERS

#include <stdbool.h>
#include "../s21_decimal.h"

void int_to_bits(int n, bool *bin_n);
void decimal_to_bits(s21_decimal value, bool *bin);
void print_int_bitwise(int n);
void print_decimal_bitwise(s21_decimal value);
void print_decimal(s21_decimal value);
void print_double_bitwise(double d);

#endif