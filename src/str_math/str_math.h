#ifndef LIB_STR_ARITHMETIC
#define LIB_STR_ARITHMETIC

#include <stdbool.h>

bool str_greater(char *str1, char *str2);
bool str_greater_or_equals(char *str1, char *str2);
bool str_less(char *str1, char *str2);
bool str_less_or_equals(char *str1, char *str2);
bool str_equals(char *str1, char *str2);

int str_pow(char *dst, char *str, char *power);
int str_powof2(char *dst, int power);

int str_sum(char *dst, char *str1, char *str2);
int str_diff(char *dst, char *str1, char *str2);

int str_mult(char *dst, char *str, char *multiplier);

#endif