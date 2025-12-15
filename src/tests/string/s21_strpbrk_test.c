#include <string.h>

#include "../../s21_string.h"
#include "string_suite.h"

START_TEST(test_s21_strpbrk_normal) {
  char str1[10] = "123456789";
  char str2[10] = "123";
  char *res = s21_strpbrk(str1, str2);
  char *expected = strpbrk(str1, str2);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strpbrk_empty) {
  char str1[10] = "";
  char str2[10] = "abcdef";
  char *res = s21_strpbrk(str1, str2);
  char *expected = strpbrk(str1, str2);
  if (expected == NULL)
    ck_assert_ptr_null(res);
  else
    ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strpbrk_no_match) {
  char str1[10] = "123456789";
  char str2[10] = "xyz";
  char *res = s21_strpbrk(str1, str2);
  char *expected = strpbrk(str1, str2);
  if (expected == NULL)
    ck_assert_ptr_null(res);
  else
    ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strpbrk_no_match_empty) {
  char str1[10] = "";
  char str2[10] = "xyz";
  char *res = s21_strpbrk(str1, str2);
  char *expected = strpbrk(str1, str2);
  if (expected == NULL)
    ck_assert_ptr_null(res);
  else
    ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strpbrk_no_common_characters) {
  char str1[10] = "123456789";
  char str2[10] = "abc";
  char *res = s21_strpbrk(str1, str2);
  char *expected = strpbrk(str1, str2);
  ck_assert_ptr_eq(res, expected);
}

START_TEST(test_s21_strpbrk_empty_str1) {
  char str1[10] = "";
  char str2[10] = "123";
  char *res = s21_strpbrk(str1, str2);
  char *expected = strpbrk(str1, str2);
  ck_assert_ptr_eq(res, expected);
}

START_TEST(test_s21_strpbrk_empty_str2) {
  char str1[10] = "123456789";
  char str2[10] = "";
  char *res = s21_strpbrk(str1, str2);
  char *expected = strpbrk(str1, str2);
  ck_assert_ptr_eq(res, expected);
}

START_TEST(test_s21_strpbrk_both_empty) {
  char str1[10] = "";
  char str2[10] = "";
  char *res = s21_strpbrk(str1, str2);
  char *expected = strpbrk(str1, str2);
  ck_assert_ptr_eq(res, expected);
}

START_TEST(test_s21_strpbrk_single_character_match) {
  char str1[10] = "123456789";
  char str2[10] = "7";
  char *res = s21_strpbrk(str1, str2);
  char *expected = strpbrk(str1, str2);
  ck_assert_str_eq(res, expected);
}

START_TEST(test_s21_strpbrk_multiple_characters_match) {
  char str1[10] = "123456789";
  char str2[10] = "58";
  char *res = s21_strpbrk(str1, str2);
  char *expected = strpbrk(str1, str2);
  ck_assert_str_eq(res, expected);
}

extern TCase *tcase_s21_strpbrk(void);

TCase *tcase_s21_strpbrk(void) {
  TCase *tcase = tcase_create("s21_strpbrk");
  tcase_add_test(tcase, test_s21_strpbrk_normal);
  tcase_add_test(tcase, test_s21_strpbrk_empty);
  tcase_add_test(tcase, test_s21_strpbrk_no_match);
  tcase_add_test(tcase, test_s21_strpbrk_no_match_empty);
  tcase_add_test(tcase, test_s21_strpbrk_no_common_characters);
  tcase_add_test(tcase, test_s21_strpbrk_empty_str1);
  tcase_add_test(tcase, test_s21_strpbrk_empty_str2);
  tcase_add_test(tcase, test_s21_strpbrk_both_empty);
  tcase_add_test(tcase, test_s21_strpbrk_single_character_match);
  tcase_add_test(tcase, test_s21_strpbrk_multiple_characters_match);

  return tcase;
}
