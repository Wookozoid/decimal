#include <stdio.h>
#include "test.h"
#include "../str_math/str_math.h"

START_TEST(test_str_math_1) {
    char str1[42] = ""; 
    char str2[42] = "";
    char res[42] = "";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_2) {
    char str1[42] = "0"; 
    char str2[42] = "0";
    char res[42] = "0";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_3) {
    char str1[42] = "0"; 
    char str2[42] = "1";
    char res[42] = "1";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_4) {
    char str1[42] = "0"; 
    char str2[42] = "2";
    char res[42] = "2";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_5) {
    char str1[42] = "0"; 
    char str2[42] = "32";
    char res[42] = "32";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_6) {
    char str1[42] = "32"; 
    char str2[42] = "32";
    char res[42] = "64";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_7) {
    char str1[42] = "37"; 
    char str2[42] = "69";
    char res[42] = "106";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_8) {
    char str1[42] = "115"; 
    char str2[42] = "1248";
    char res[42] = "1363";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_9) {
    char str1[42] = "112515"; 
    char str2[42] = "19415";
    char res[42] = "131930";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_10) {
    char str1[42] = "90510520175701952"; 
    char str2[42] = "5029851251250125";
    char res[42] = "95540371426952077";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_11) {
    char str1[42] = "-92835"; 
    char str2[42] = "-1529085901";
    char res[42] = "-1529178736";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_12) {
    char str1[42] = "-112515"; 
    char str2[42] = "19415";
    char res[42] = "-93100";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_13) {
    char str1[42] = "-905125198"; 
    char str2[42] = "8652882366263";
    char res[42] = "8651977241065";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_14) {
    char str1[42] = "-152981985219859815"; 
    char str2[42] = "12858521";
    char res[42] = "-152981985207001294";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_15) {
    char str1[42] = "112519259815215"; 
    char str2[42] = "-192156124175";
    char res[42] = "112327103691040";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_16) {
    char str1[42] = "-9999"; 
    char str2[42] = "1000000";
    char res[42] = "990001";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_17) {
    char str1[42] = "-9999"; 
    char str2[42] = "-9999999";
    char res[42] = "-10009998";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_18) {
    char str1[42] = "-81529"; 
    char str2[42] = "152151678";
    char res[42] = "152070149";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_19) {
    char str1[42] = "-81529980217501"; 
    char str2[42] = "980125";
    char res[42] = "-81529979237376";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_20) {
    char str1[42] = "908125"; 
    char str2[42] = "-18725198752";
    char res[42] = "-18724290627";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_21) {
    char str1[42] = "12549815908125"; 
    char str2[42] = "-871532";
    char res[42] = "12549815036593";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_22) {
    char str1[42] = "12549815908125"; 
    char str2[42] = "-85894501854398";
    char res[42] = "-73344685946273";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_23) {
    char str1[42] = "0"; 
    char str2[42] = "-1";
    char res[42] = "-1";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_24) {
    char str1[42] = "-1"; 
    char str2[42] = "0";
    char res[42] = "-1";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_25) {
    char str1[42] = "-1"; 
    char str2[42] = "0";
    char res[42] = "-1";

    str_diff(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_26) {
    char str1[42] = "-123456789"; 
    char str2[42] = "-123456789";
    char res[42] = "0";

    str_diff(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_27) {
    char str1[42] = "-91258715"; 
    char str2[42] = "-119825";
    char res[42] = "-91138890";

    str_diff(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_28) {
    char str1[42] = "-91258715"; 
    char str2[42] = "119825";
    char res[42] = "-91378540";

    str_diff(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_29) {
    char str1[42] = "912589801715"; 
    char str2[42] = "1248152";
    char res[42] = "912588553563";

    str_diff(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_30) {
    char str1[42] = "824151"; 
    char str2[42] = "15198025";
    char res[42] = "-14373874";

    str_diff(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_31) {
    char str1[42] = "-824151"; 
    char str2[42] = "-15198025";
    char res[42] = "14373874";

    str_diff(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_32) {
    char str1[42] = "-82415198051"; 
    char str2[42] = "-91591254";
    char res[42] = "-82323606797";

    str_diff(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_math_33) {
    char str1[42] = "-82415198051"; 
    char str2[42] = "-97492184150";
    char res[42] = "15076986099";

    str_diff(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_mult_1) {
    char str1[42] = "82415198051"; 
    char str2[42] = "97492184150";
    char res[42] = "8034837665146813091650";

    str_mult(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_mult_2) {
    char str1[42] = "123"; 
    char str2[42] = "15";
    char res[42] = "1845";

    str_mult(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_mult_3) {
    char str1[42] = "123"; 
    char str2[42] = "1";
    char res[42] = "123";

    str_mult(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_mult_4) {
    char str1[42] = "123"; 
    char str2[42] = "0";
    char res[42] = "0";

    str_mult(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_mult_5) {
    char str1[42] = "0"; 
    char str2[42] = "123";
    char res[42] = "0";

    str_mult(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_mult_6) {
    char str1[42] = "1"; 
    char str2[42] = "123";
    char res[42] = "123";

    str_mult(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_mult_7) {
    char str1[42] = "99999999"; 
    char str2[42] = "999999";
    char res[42] = "99999899000001";

    str_mult(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_mult_8) {
    char str1[42] = "999999999872154980175"; 
    char str2[42] = "999999132516";
    char res[42] = "999999132388155091078509177870300";

    str_mult(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_mult_9) {
    char str1[42] = "999999999872154980175"; 
    char str2[42] = "1";
    char res[42] = "999999999872154980175";

    str_mult(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_mult_10) {
    char str1[42] = "999999999872154980175"; 
    char str2[42] = "0";
    char res[42] = "0";

    str_mult(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_mult_11) {
    char str1[42] = "0"; 
    char str2[42] = "999999999872154980175";
    char res[42] = "0";

    str_mult(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_mult_12) {
    char str1[42] = "1"; 
    char str2[42] = "999999999872154980175";
    char res[42] = "999999999872154980175";

    str_mult(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_mult_13) {
    char str1[42] = "-1"; 
    char str2[42] = "999999999872154980175";
    char res[42] = "-999999999872154980175";

    str_mult(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_mult_14) {
    char str1[42] = "0"; 
    char str2[42] = "-999999999872154980175";
    char res[42] = "0";

    str_mult(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_mult_15) {
    char str1[42] = "-1"; 
    char str2[42] = "-999999999872154980175";
    char res[42] = "999999999872154980175";

    str_mult(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_mult_16) {
    char str1[42] = "-999999999872154980175"; 
    char str2[42] = "999999132516";
    char res[42] = "-999999132388155091078509177870300";

    str_mult(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_mult_17) {
    char str1[42] = "-999999999872154980175"; 
    char str2[42] = "-999999132516";
    char res[42] = "999999132388155091078509177870300";

    str_mult(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_pow_1) {
    char str1[42] = "1"; 
    char str2[42] = "28";
    char res[42] = "1";

    str_pow(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_pow_2) {
    char str1[42] = "2"; 
    char str2[42] = "10";
    char res[42] = "1024";

    str_pow(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_pow_3) {
    char str1[42] = "3"; 
    char str2[42] = "45";
    char res[42] = "2954312706550833698643";

    str_pow(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_pow_4) {
    char str1[42] = "12376587"; 
    char str2[42] = "1";
    char res[42] = "12376587";

    str_pow(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_pow_5) {
    char str1[42] = "0"; 
    char str2[42] = "1";
    char res[42] = "0";

    str_pow(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_pow_6) {
    char str1[42] = "0"; 
    char str2[42] = "98124";
    char res[42] = "0";

    str_pow(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_pow_7) {
    char str1[42] = "19052"; 
    char str2[42] = "0";
    char res[42] = "1";

    str_pow(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_pow_8) {
    char str1[42] = "1"; 
    char str2[42] = "0";
    char res[42] = "1";

    str_pow(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

static void test_sum(TCase *tc_core) {
    tcase_add_test(tc_core, test_str_math_1);
    tcase_add_test(tc_core, test_str_math_2);
    tcase_add_test(tc_core, test_str_math_3);
    tcase_add_test(tc_core, test_str_math_4);
    tcase_add_test(tc_core, test_str_math_5);
    tcase_add_test(tc_core, test_str_math_6);
    tcase_add_test(tc_core, test_str_math_7);
    tcase_add_test(tc_core, test_str_math_8);
    tcase_add_test(tc_core, test_str_math_9);
    tcase_add_test(tc_core, test_str_math_10);
    tcase_add_test(tc_core, test_str_math_11);
    tcase_add_test(tc_core, test_str_math_12);
    tcase_add_test(tc_core, test_str_math_13);
    tcase_add_test(tc_core, test_str_math_14);
    tcase_add_test(tc_core, test_str_math_15);
    tcase_add_test(tc_core, test_str_math_16);
    tcase_add_test(tc_core, test_str_math_17);
    tcase_add_test(tc_core, test_str_math_18);
    tcase_add_test(tc_core, test_str_math_19);
    tcase_add_test(tc_core, test_str_math_20);
    tcase_add_test(tc_core, test_str_math_21);
    tcase_add_test(tc_core, test_str_math_22);
    tcase_add_test(tc_core, test_str_math_23);
    tcase_add_test(tc_core, test_str_math_24);
}

static void test_diff(TCase *tc_core) {
    tcase_add_test(tc_core, test_str_math_25);
    tcase_add_test(tc_core, test_str_math_26);
    tcase_add_test(tc_core, test_str_math_27);
    tcase_add_test(tc_core, test_str_math_28);
    tcase_add_test(tc_core, test_str_math_29);
    tcase_add_test(tc_core, test_str_math_30);
    tcase_add_test(tc_core, test_str_math_31);
    tcase_add_test(tc_core, test_str_math_32);
    tcase_add_test(tc_core, test_str_math_33);
}

static void test_mult(TCase *tc_core) {
    tcase_add_test(tc_core, test_str_mult_1);
    tcase_add_test(tc_core, test_str_mult_2);
    tcase_add_test(tc_core, test_str_mult_3);
    tcase_add_test(tc_core, test_str_mult_4);
    tcase_add_test(tc_core, test_str_mult_5);
    tcase_add_test(tc_core, test_str_mult_6);
    tcase_add_test(tc_core, test_str_mult_7);
    tcase_add_test(tc_core, test_str_mult_8);
    tcase_add_test(tc_core, test_str_mult_9);
    tcase_add_test(tc_core, test_str_mult_10);
    tcase_add_test(tc_core, test_str_mult_11);
    tcase_add_test(tc_core, test_str_mult_12);
    tcase_add_test(tc_core, test_str_mult_13);
    tcase_add_test(tc_core, test_str_mult_14);
    tcase_add_test(tc_core, test_str_mult_15);
    tcase_add_test(tc_core, test_str_mult_16);
    tcase_add_test(tc_core, test_str_mult_17);
}

static void test_pow(TCase *tc_core) {
    tcase_add_test(tc_core, test_str_pow_1);
    tcase_add_test(tc_core, test_str_pow_2);
    tcase_add_test(tc_core, test_str_pow_3);
    tcase_add_test(tc_core, test_str_pow_4);
    tcase_add_test(tc_core, test_str_pow_5);
    tcase_add_test(tc_core, test_str_pow_6);
    tcase_add_test(tc_core, test_str_pow_7);
    tcase_add_test(tc_core, test_str_pow_8);
}

Suite *test_str_math() {
    Suite *s = suite_create("test_str_math");
    TCase *tc_core = tcase_create("Core");    

    test_sum(tc_core);
    test_diff(tc_core);
    test_mult(tc_core);
    test_pow(tc_core);

    suite_add_tcase(s, tc_core);

    return s;
}
