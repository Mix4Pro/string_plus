#include <string.h>

#include "../../s21_string.h"
#include "string_suite.h"

START_TEST(test_s21_trim_normal) {
  char *src = "   Hello World   ";
  char *trim_chars = " ";
  char *expected = "Hello World";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_leading_and_trailing) {
  char *src = "###Hello World###";
  char *trim_chars = "#";
  char *expected = "Hello World";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_all_trimmed) {
  char *src = "   ";
  char *trim_chars = " ";
  char *expected = "";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_null_src) {
  char *src = NULL;
  char *trim_chars = " ";
  ck_assert_ptr_eq(s21_trim(src, trim_chars), NULL);
}
END_TEST

START_TEST(test_s21_trim_empty_trim_chars) {
  char *src = "   Hello World   ";
  char *trim_chars = "";
  char *expected = "   Hello World   ";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_only_trim_chars) {
  char *src = "###";
  char *trim_chars = "#";
  char *expected = "";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

extern TCase *tcase_s21_trim(void);

TCase *tcase_s21_trim(void) {
  TCase *tcase = tcase_create("s21_trim");
  tcase_add_test(tcase, test_s21_trim_normal);
  tcase_add_test(tcase, test_s21_trim_leading_and_trailing);
  tcase_add_test(tcase, test_s21_trim_all_trimmed);
  tcase_add_test(tcase, test_s21_trim_null_src);
  tcase_add_test(tcase, test_s21_trim_empty_trim_chars);
  tcase_add_test(tcase, test_s21_trim_only_trim_chars);
  return tcase;
}