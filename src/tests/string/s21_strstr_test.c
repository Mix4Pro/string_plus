#include <string.h>

#include "../../s21_string.h"
#include "string_suite.h"

START_TEST(test_s21_strstr_normal) {
  char str1[10] = "123456789";
  char str2[10] = "456";
  char *res = s21_strstr(str1, str2);
  char *expected = strstr(str1, str2);
  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strstr_empty) {
  char str1[10] = "";
  char str2[10] = "456";
  char *res = s21_strstr(str1, str2);
  char *expected = strstr(str1, str2);
  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strstr_not_found) {
  char str1[10] = "123456789";
  char str2[10] = "abc";
  char *res = s21_strstr(str1, str2);
  char *expected = strstr(str1, str2);
  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strstr_null_char) {
  char str1[10] = "123456789";
  char str2[10] = "4\0";
  char *res = s21_strstr(str1, str2);
  char *expected = strstr(str1, str2);
  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strstr_null_char2) {
  char str1[10] = "123456789";
  char str2[10] = "\0";
  char *res = s21_strstr(str1, str2);
  char *expected = strstr(str1, str2);
  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strstr_needle_at_beginning) {
  char haystack[20] = "abcdefg";
  char needle[10] = "abc";
  char *res = s21_strstr(haystack, needle);
  char *expected = strstr(haystack, needle);
  ck_assert_ptr_eq(res, expected);
}

START_TEST(test_s21_strstr_needle_at_end) {
  char haystack[20] = "abcdefg";
  char needle[10] = "efg";
  char *res = s21_strstr(haystack, needle);
  char *expected = strstr(haystack, needle);
  ck_assert_ptr_eq(res, expected);
}

START_TEST(test_s21_strstr_needle_same_as_haystack) {
  char haystack[20] = "haystack";
  char needle[20] = "haystack";
  char *res = s21_strstr(haystack, needle);
  char *expected = strstr(haystack, needle);
  ck_assert_ptr_eq(res, expected);
}

START_TEST(test_s21_strstr_empty_needle) {
  char haystack[20] = "abcdefg";
  char needle[1] = "";
  char *res = s21_strstr(haystack, needle);
  char *expected = strstr(haystack, needle);
  ck_assert_ptr_eq(res, expected);
}

START_TEST(test_s21_strstr_empty_haystack) {
  char haystack[1] = "";
  char needle[10] = "test";
  char *res = s21_strstr(haystack, needle);
  char *expected = strstr(haystack, needle);
  ck_assert_ptr_eq(res, expected);
}

START_TEST(test_s21_strstr_no_match) {
  char haystack[20] = "abcdefg";
  char needle[10] = "xyz";
  char *res = s21_strstr(haystack, needle);
  char *expected = strstr(haystack, needle);
  ck_assert_ptr_eq(res, expected);
}

extern TCase *tcase_s21_strstr(void);

TCase *tcase_s21_strstr(void) {
  TCase *tcase = tcase_create("s21_strstr");
  tcase_add_test(tcase, test_s21_strstr_normal);
  tcase_add_test(tcase, test_s21_strstr_empty);
  tcase_add_test(tcase, test_s21_strstr_not_found);
  tcase_add_test(tcase, test_s21_strstr_null_char);
  tcase_add_test(tcase, test_s21_strstr_null_char2);
  tcase_add_test(tcase, test_s21_strstr_needle_at_beginning);
  tcase_add_test(tcase, test_s21_strstr_needle_at_end);
  tcase_add_test(tcase, test_s21_strstr_needle_same_as_haystack);
  tcase_add_test(tcase, test_s21_strstr_empty_needle);
  tcase_add_test(tcase, test_s21_strstr_empty_haystack);
  tcase_add_test(tcase, test_s21_strstr_no_match);

  return tcase;
}
