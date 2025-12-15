#include <string.h>

#include "../../s21_string.h"
#include "string_suite.h"

START_TEST(test_s21_strlen_normal) {
  char str[10] = "123456789";
  s21_size_t res = s21_strlen(str);
  s21_size_t expected = strlen(str);
  ck_assert_int_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strlen_empty) {
  char str[10] = "";
  s21_size_t res = s21_strlen(str);
  s21_size_t expected = strlen(str);
  ck_assert_int_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strlen_long_string) {
  char str[1024] =
      "This is a long string with more than 100 characters. It should be long "
      "enough to test the s21_strlen function properly.";
  s21_size_t res = s21_strlen(str);
  s21_size_t expected = strlen(str);
  ck_assert_int_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strlen_string_with_null_chars) {
  char str[] = "Hello\0world";
  s21_size_t res = s21_strlen(str);
  s21_size_t expected = strlen(str);
  ck_assert_int_eq(res, expected);
}
END_TEST

START_TEST(strlen_1) {
  const char str[] = "This is a test string";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_2) {
  const char str[] = "";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_3) {
  const char str[] = "\0\0\0";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_4) {
  const char str[] = "1234567890";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_5) {
  const char str[] = "??$#@!@*";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_6) {
  const char str[] = "This is test\0 string";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_7) {
  const char *str = NULL;
  ck_assert_int_eq(s21_strlen(str), 0);
}
END_TEST

extern TCase *tcase_s21_strlen(void);

TCase *tcase_s21_strlen(void) {
  TCase *tcase = tcase_create("s21_strlen");
  tcase_add_test(tcase, test_s21_strlen_normal);
  tcase_add_test(tcase, test_s21_strlen_empty);
  tcase_add_test(tcase, test_s21_strlen_long_string);
  tcase_add_test(tcase, test_s21_strlen_string_with_null_chars);
  tcase_add_test(tcase, strlen_1);
  tcase_add_test(tcase, strlen_2);
  tcase_add_test(tcase, strlen_3);
  tcase_add_test(tcase, strlen_4);
  tcase_add_test(tcase, strlen_5);
  tcase_add_test(tcase, strlen_6);
  tcase_add_test(tcase, strlen_7);

  return tcase;
}
