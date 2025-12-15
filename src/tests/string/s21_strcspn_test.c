#include <string.h>

#include "../../s21_string.h"
#include "string_suite.h"

START_TEST(test_s21_strcspn_normal) {
  char str1[] = "abcdef";
  char str2[] = "xyz";
  s21_size_t res = s21_strcspn(str1, str2);
  s21_size_t expected = strcspn(str1, str2);
  ck_assert_int_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strcspn_first_char_in_str2) {
  char str1[] = "abc";
  char str2[] = "adef";
  s21_size_t res = s21_strcspn(str1, str2);
  s21_size_t expected = strcspn(str1, str2);
  ck_assert_int_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strcspn_all_chars_in_str2) {
  char str1[] = "abcdef";
  char str2[] = "abcdef";
  s21_size_t res = s21_strcspn(str1, str2);
  s21_size_t expected = strcspn(str1, str2);
  ck_assert_int_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strcspn_empty_str1) {
  char str1[] = "";
  char str2[] = "abc";
  s21_size_t res = s21_strcspn(str1, str2);
  s21_size_t expected = strcspn(str1, str2);
  ck_assert_int_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strcspn_empty_str2) {
  char str1[] = "abc";
  char str2[] = "";
  s21_size_t res = s21_strcspn(str1, str2);
  s21_size_t expected = strcspn(str1, str2);
  ck_assert_int_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strcspn_empty) {
  char str1[] = "";
  char str2[] = "";
  s21_size_t res = s21_strcspn(str1, str2);
  s21_size_t expected = strcspn(str1, str2);
  ck_assert_int_eq(res, expected);
}
END_TEST

extern TCase *tcase_s21_strcspn(void);

TCase *tcase_s21_strcspn(void) {
  TCase *tcase = tcase_create("s21_strcspn");
  tcase_add_test(tcase, test_s21_strcspn_normal);
  tcase_add_test(tcase, test_s21_strcspn_first_char_in_str2);
  tcase_add_test(tcase, test_s21_strcspn_all_chars_in_str2);
  tcase_add_test(tcase, test_s21_strcspn_empty_str1);
  tcase_add_test(tcase, test_s21_strcspn_empty_str2);
  tcase_add_test(tcase, test_s21_strcspn_empty);

  return tcase;
}
