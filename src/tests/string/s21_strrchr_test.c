#include <string.h>

#include "../../s21_string.h"
#include "string_suite.h"

START_TEST(test_s21_strrchr_normal) {
  char str[10] = "123456789";
  char *res = s21_strrchr(str, '4');
  char *expected = strrchr(str, '4');
  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strrchr_empty) {
  char str[10] = "";
  char *res = s21_strrchr(str, '4');
  char *expected = strrchr(str, '4');
  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strrchr_not_found) {
  char str[10] = "123456789";
  char *res = s21_strrchr(str, 'a');
  char *expected = strrchr(str, 'a');
  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strrchr_null_char) {
  char str[10] = "123456789";
  char *res = s21_strrchr(str, '\0');
  char *expected = strrchr(str, '\0');
  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strrchr_empty_str) {
  char str[10] = "";
  int c = '0';
  char *res = s21_strrchr(str, c);
  char *expected = strrchr(str, c);
  ck_assert_ptr_eq(res, expected);
}

START_TEST(test_s21_strrchr_single_char_match) {
  char str[10] = "123456789";
  int c = '1';
  char *res = s21_strrchr(str, c);
  char *expected = strrchr(str, c);
  ck_assert_ptr_eq(res, expected);
}

START_TEST(test_s21_strrchr_last_char_match) {
  char str[10] = "123456789";
  int c = '9';
  char *res = s21_strrchr(str, c);
  char *expected = strrchr(str, c);
  ck_assert_ptr_eq(res, expected);
}

START_TEST(test_s21_strrchr_repeated_char) {
  char str[10] = "1234554321";
  int c = '5';
  char *res = s21_strrchr(str, c);
  char *expected = strrchr(str, c);
  ck_assert_ptr_eq(res, expected);
}

START_TEST(strchr_1) {
  const char str[] = "This is a test string";
  char c = 's';
  ck_assert_pstr_eq(s21_strchr(str, (int)c), strchr(str, (int)c));
}
END_TEST

START_TEST(strchr_2) {
  const char str[] = "0123456789";
  char c = '5';
  ck_assert_pstr_eq(s21_strchr(str, (int)c), strchr(str, (int)c));
}
END_TEST

START_TEST(strchr_3) {
  const char str[] = "Hello, world!";
  char c = 'z';
  ck_assert_pstr_eq(s21_strchr(str, (int)c), strchr(str, (int)c));
}
END_TEST

START_TEST(strchr_4) {
  const char str[] = "This is a test string";
  char c = 's';

  ck_assert_pstr_eq(s21_strchr(str, (int)c), strchr(str, (int)c));
}
END_TEST

START_TEST(strchr_5) {
  const char str[] = "\0";
  char c = 's';
  ck_assert_pstr_eq(s21_strchr(str, (int)c), strchr(str, (int)c));
}
END_TEST

START_TEST(strchr_6) {
  const char str[] = "\0\0\0";
  char c = '\0';
  ck_assert_pstr_eq(s21_strchr(str, (int)c), strchr(str, (int)c));
}
END_TEST

START_TEST(strchr_7) {
  const char str[] = "school 21";
  char c = ' ';
  ck_assert_pstr_eq(s21_strchr(str, (int)c), strchr(str, (int)c));
}
END_TEST

START_TEST(strchr_8) {
  const char str[] = "\0school 21";
  char c = '1';
  ck_assert_pstr_eq(s21_strchr(str, (int)c), strchr(str, (int)c));
}
END_TEST

START_TEST(strchr_9) {
  const char str[] = "Hello, world!";
  char c = ',';
  ck_assert_pstr_eq(s21_strchr(str, (int)c), strchr(str, (int)c));
}
END_TEST

START_TEST(strchr_10) {
  const char str[] = "B\0AAAAAAAAAAAAAAAAAA!";
  char c = 'A';

  ck_assert_pstr_eq(s21_strchr(str, (int)c), strchr(str, (int)c));
}
END_TEST

extern TCase *tcase_s21_strrchr(void);

TCase *tcase_s21_strrchr(void) {
  TCase *tcase = tcase_create("s21_strrchr");
  tcase_add_test(tcase, test_s21_strrchr_normal);
  tcase_add_test(tcase, test_s21_strrchr_empty);
  tcase_add_test(tcase, test_s21_strrchr_not_found);
  tcase_add_test(tcase, test_s21_strrchr_null_char);
  tcase_add_test(tcase, test_s21_strrchr_empty_str);
  tcase_add_test(tcase, test_s21_strrchr_single_char_match);
  tcase_add_test(tcase, test_s21_strrchr_last_char_match);
  tcase_add_test(tcase, test_s21_strrchr_repeated_char);
  tcase_add_test(tcase, strchr_1);
  tcase_add_test(tcase, strchr_2);
  tcase_add_test(tcase, strchr_3);
  tcase_add_test(tcase, strchr_4);
  tcase_add_test(tcase, strchr_5);
  tcase_add_test(tcase, strchr_6);
  tcase_add_test(tcase, strchr_7);
  tcase_add_test(tcase, strchr_8);
  tcase_add_test(tcase, strchr_9);
  tcase_add_test(tcase, strchr_10);

  return tcase;
}
