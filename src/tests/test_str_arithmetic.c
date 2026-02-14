#include <stdio.h>
#include "test.h"
#include "../str_math/str_math.h"

START_TEST(test_str_arithmetic_1) {
    char str1[42] = ""; 
    char str2[42] = "";
    char res[42] = "";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_2) {
    char str1[42] = "0"; 
    char str2[42] = "0";
    char res[42] = "0";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_3) {
    char str1[42] = "0"; 
    char str2[42] = "1";
    char res[42] = "1";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_4) {
    char str1[42] = "0"; 
    char str2[42] = "2";
    char res[42] = "2";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_5) {
    char str1[42] = "0"; 
    char str2[42] = "32";
    char res[42] = "32";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_6) {
    char str1[42] = "32"; 
    char str2[42] = "32";
    char res[42] = "64";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_7) {
    char str1[42] = "37"; 
    char str2[42] = "69";
    char res[42] = "106";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_8) {
    char str1[42] = "115"; 
    char str2[42] = "1248";
    char res[42] = "1363";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_9) {
    char str1[42] = "112515"; 
    char str2[42] = "19415";
    char res[42] = "131930";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_10) {
    char str1[42] = "90510520175701952"; 
    char str2[42] = "5029851251250125";
    char res[42] = "95540371426952077";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_11) {
    char str1[42] = "-92835"; 
    char str2[42] = "-1529085901";
    char res[42] = "-1529178736";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_12) {
    char str1[42] = "-112515"; 
    char str2[42] = "19415";
    char res[42] = "-93100";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_13) {
    char str1[42] = "-905125198"; 
    char str2[42] = "8652882366263";
    char res[42] = "8651977241065";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_14) {
    char str1[42] = "-152981985219859815"; 
    char str2[42] = "12858521";
    char res[42] = "-152981985207001294";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_15) {
    char str1[42] = "112519259815215"; 
    char str2[42] = "-192156124175";
    char res[42] = "112327103691040";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_16) {
    char str1[42] = "-9999"; 
    char str2[42] = "1000000";
    char res[42] = "990001";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_17) {
    char str1[42] = "-9999"; 
    char str2[42] = "-9999999";
    char res[42] = "-10009998";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_18) {
    char str1[42] = "-81529"; 
    char str2[42] = "152151678";
    char res[42] = "152070149";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_19) {
    char str1[42] = "-81529980217501"; 
    char str2[42] = "980125";
    char res[42] = "-81529979237376";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_20) {
    char str1[42] = "908125"; 
    char str2[42] = "-18725198752";
    char res[42] = "-18724290627";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_21) {
    char str1[42] = "12549815908125"; 
    char str2[42] = "-871532";
    char res[42] = "12549815036593";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_22) {
    char str1[42] = "12549815908125"; 
    char str2[42] = "-85894501854398";
    char res[42] = "-73344685946273";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_23) {
    char str1[42] = "0"; 
    char str2[42] = "-1";
    char res[42] = "-1";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_24) {
    char str1[42] = "-1"; 
    char str2[42] = "0";
    char res[42] = "-1";

    str_sum(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_25) {
    char str1[42] = "-1"; 
    char str2[42] = "0";
    char res[42] = "-1";

    str_diff(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_26) {
    char str1[42] = "-123456789"; 
    char str2[42] = "-123456789";
    char res[42] = "0";

    str_diff(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_27) {
    char str1[42] = "-91258715"; 
    char str2[42] = "-119825";
    char res[42] = "-91138890";

    str_diff(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_28) {
    char str1[42] = "-91258715"; 
    char str2[42] = "119825";
    char res[42] = "-91378540";

    str_diff(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_29) {
    char str1[42] = "912589801715"; 
    char str2[42] = "1248152";
    char res[42] = "912588553563";

    str_diff(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_30) {
    char str1[42] = "824151"; 
    char str2[42] = "15198025";
    char res[42] = "-14373874";

    str_diff(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_31) {
    char str1[42] = "-824151"; 
    char str2[42] = "-15198025";
    char res[42] = "14373874";

    str_diff(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_32) {
    char str1[42] = "-82415198051"; 
    char str2[42] = "-91591254";
    char res[42] = "-82323606797";

    str_diff(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

START_TEST(test_str_arithmetic_33) {
    char str1[42] = "-82415198051"; 
    char str2[42] = "-97492184150";
    char res[42] = "15076986099";

    str_diff(str1, str1, str2);

    ck_assert_str_eq(res, str1);
}
END_TEST

static void test_sum(TCase *tc_core) {
    tcase_add_test(tc_core, test_str_arithmetic_1);
    tcase_add_test(tc_core, test_str_arithmetic_2);
    tcase_add_test(tc_core, test_str_arithmetic_3);
    tcase_add_test(tc_core, test_str_arithmetic_4);
    tcase_add_test(tc_core, test_str_arithmetic_5);
    tcase_add_test(tc_core, test_str_arithmetic_6);
    tcase_add_test(tc_core, test_str_arithmetic_7);
    tcase_add_test(tc_core, test_str_arithmetic_8);
    tcase_add_test(tc_core, test_str_arithmetic_9);
    tcase_add_test(tc_core, test_str_arithmetic_10);
    tcase_add_test(tc_core, test_str_arithmetic_11);
    tcase_add_test(tc_core, test_str_arithmetic_12);
    tcase_add_test(tc_core, test_str_arithmetic_13);
    tcase_add_test(tc_core, test_str_arithmetic_14);
    tcase_add_test(tc_core, test_str_arithmetic_15);
    tcase_add_test(tc_core, test_str_arithmetic_16);
    tcase_add_test(tc_core, test_str_arithmetic_17);
    tcase_add_test(tc_core, test_str_arithmetic_18);
    tcase_add_test(tc_core, test_str_arithmetic_19);
    tcase_add_test(tc_core, test_str_arithmetic_20);
    tcase_add_test(tc_core, test_str_arithmetic_21);
    tcase_add_test(tc_core, test_str_arithmetic_22);
    tcase_add_test(tc_core, test_str_arithmetic_23);
    tcase_add_test(tc_core, test_str_arithmetic_24);
}

static void test_difference(TCase *tc_core) {
    tcase_add_test(tc_core, test_str_arithmetic_25);
    tcase_add_test(tc_core, test_str_arithmetic_26);
    tcase_add_test(tc_core, test_str_arithmetic_27);
    tcase_add_test(tc_core, test_str_arithmetic_28);
    tcase_add_test(tc_core, test_str_arithmetic_29);
    tcase_add_test(tc_core, test_str_arithmetic_30);
    tcase_add_test(tc_core, test_str_arithmetic_31);
    tcase_add_test(tc_core, test_str_arithmetic_32);
    tcase_add_test(tc_core, test_str_arithmetic_33);
}

Suite *test_str_arithmetic() {
    Suite *s = suite_create("test_str_arithmetic");
    TCase *tc_core = tcase_create("Core");    

    test_sum(tc_core);
    test_difference(tc_core);

    suite_add_tcase(s, tc_core);

    return s;
}
