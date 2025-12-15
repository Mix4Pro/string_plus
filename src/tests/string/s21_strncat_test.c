#include <string.h>

#include "../../s21_string.h"
#include "string_suite.h"

START_TEST(strncat_1) {
  char str1[50] = "This is a test string";
  char str1_copy[50] = "This is a test string";
  const char str2[] = "21";

  char *res1 = s21_strncat(str1, str2, s21_strlen(str1) + 5);
  char *res2 = strncat(str1_copy, str2, s21_strlen(str1) + 5);

  ck_assert_ptr_eq(res1, str1);
  ck_assert_ptr_eq(res2, str1_copy);
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(strncat_2) {
  char str1[3] = "";
  char str1_copy[3] = "";
  const char str2[] = "21";

  s21_strncat(str1, str2, s21_strlen(str1));
  strncat(str1_copy, str2, s21_strlen(str1));
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(strncat_3) {
  char str1[256] = "This is a test string";
  char str1_copy[256] = "This is a test string";
  const char str2[4] = "";

  s21_strncat(str1, str2, 4);
  strncat(str1_copy, str2, 4);
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(strncat_4) {
  char str1[20] = "Hello, ";
  char str1_copy[20] = "Hello, ";
  const char str2[] = "world!";

  s21_strncat(str1, str2, s21_strlen(str2));
  strncat(str1_copy, str2, s21_strlen(str2));
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(strncat_5) {
  char str1[] = "\0\0";
  char str1_copy[] = "\0\0";
  const char str2[] = "!";

  s21_strncat(str1, str2, s21_strlen(str2));
  strncat(str1_copy, str2, s21_strlen(str2));
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(strncat_6) {
  char str1[] = "12345\0 23455     ";
  char str1_copy[] = "12345\0 23455     ";
  const char str2[] = "2\0 1";

  s21_strncat(str1, str2, 8);
  strncat(str1_copy, str2, 8);

  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(strncat_7) {
  char str1[20] = "School\0 21";
  char str1_copy[20] = "School\0 21";
  const char str2[] = "21";

  s21_strncat(str1, str2, s21_strlen(str2));
  strncat(str1_copy, str2, s21_strlen(str2));
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(strncat_8) {
  char str1[256] = "TEST #1231242357679790890";
  char str1_copy[256] = "TEST #1231242357679790890";
  const char str2[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

  s21_strncat(str1, str2, 34);
  strncat(str1_copy, str2, 34);
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(strncat_9) {
  char str1[17] = "test string   ";
  char str1_copy[17] = "test string   ";
  const char str2[] = "<3";

  s21_strncat(str1, str2, 2);
  strncat(str1_copy, str2, 2);
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(strncat_10) {
  char str1[9] = "1234 ";
  char str1_copy[9] = "1234 ";
  const char str2[] = "5";

  s21_strncat(str1, str2, 1);
  strncat(str1_copy, str2, 1);
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

extern TCase *tcase_s21_strncat(void);

TCase *tcase_s21_strncat(void) {
  TCase *tcase = tcase_create("s21_strncat");
  tcase_add_test(tcase, strncat_1);
  tcase_add_test(tcase, strncat_2);
  tcase_add_test(tcase, strncat_3);
  tcase_add_test(tcase, strncat_4);
  tcase_add_test(tcase, strncat_5);
  tcase_add_test(tcase, strncat_6);
  tcase_add_test(tcase, strncat_7);
  tcase_add_test(tcase, strncat_8);
  tcase_add_test(tcase, strncat_9);
  tcase_add_test(tcase, strncat_10);

  return tcase;
}
