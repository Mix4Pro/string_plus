#include <string.h>

#include "../../s21_string.h"
#include "string_suite.h"

START_TEST(test_s21_strncpy_normal) {
  char dest[10] = "123456789";
  char src[10] = "abcdef";
  char *res = s21_strncpy(dest, src, 3);
  char *expected = strncpy(dest, src, 3);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strncpy_src_shorter_than_n) {
  char dest[10] = "123456789";
  char src[10] = "abc";
  char *res = s21_strncpy(dest, src, 6);
  char *expected = strncpy(dest, src, 6);
  ck_assert_str_eq(res, expected);
}

START_TEST(test_s21_strncpy_src_same_length_as_n) {
  char dest[10] = "123456789";
  char src[10] = "abcdef";
  char *res = s21_strncpy(dest, src, 6);
  char *expected = strncpy(dest, src, 6);
  ck_assert_str_eq(res, expected);
}

START_TEST(test_s21_strncpy_src_longer_than_n) {
  char dest[10] = "123456789";
  char src[10] = "abcdefghi";
  char *res = s21_strncpy(dest, src, 6);
  char *expected = strncpy(dest, src, 6);
  ck_assert_str_eq(res, expected);
}

START_TEST(test_s21_strncpy_n_zero) {
  char dest[10] = "123456789";
  char src[10] = "abcdef";
  char *res = s21_strncpy(dest, src, 0);
  ck_assert_str_eq(res, dest);
}

START_TEST(test_s21_strncpy_dest_size_is_n) {
  char dest[6] = "12345";
  char src[10] = "abcdef";
  char *res = s21_strncpy(dest, src, 5);
  char *expected = strncpy(dest, src, 5);
  ck_assert_str_eq(res, expected);
}

START_TEST(test_s21_strncpy_dest_size_less_than_n) {
  char dest[7] = "12345";
  char src[10] = "abcdef";
  char *res = s21_strncpy(dest, src, 7);
  char *expected = strncpy(dest, src, 7);
  ck_assert_str_eq(res, expected);
}

START_TEST(test_s21_strncpy_dest_size_greater_than_n) {
  char dest[8] = "1234567";
  char src[10] = "abcdef";
  char *res = s21_strncpy(dest, src, 5);
  char *expected = strncpy(dest, src, 5);
  ck_assert_str_eq(res, expected);
}

START_TEST(test_s21_strncpy_overflow) {
  char dest[10] = "123456789";
  char src[10] = "abcdef";
  char *res = s21_strncpy(dest, src, 10);
  char *expected = strncpy(dest, src, 10);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strncpy_empty) {
  char dest[10] = "";
  char src[10] = "abcdef";
  char *res = s21_strncpy(dest, src, 3);
  char *expected = strncpy(dest, src, 3);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(test_s21_strncpy_empty_src) {
  char dest[10] = "123456789";
  char src[10] = "";
  char *res = s21_strncpy(dest, src, 3);
  char *expected = strncpy(dest, src, 3);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(s21_strncpy_test_terminating) {
  char dest[10] = "";
  char src[10] = "test\0";
  char *res = s21_strncpy(dest, src, 4);
  char *expected = strncpy(dest, src, 4);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(s21_strncpy_test_crush) {
  char dest[10] = "test ";
  char src[10] = "test\0";
  char *res = s21_strncpy(dest, src, 10);
  char *expected = strncpy(dest, src, 10);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strncpy_1) {
  char str1[] = "This is a test string";
  char str1_copy[] = "This is a test string";
  const char str2[] = "This is a test string";

  s21_strncpy(str1, str2, strlen(str1) + 1);
  strncpy(str1_copy, str2, strlen(str1) + 1);
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(strncpy_2) {
  char str1[] = "This is a test string";
  char str1_copy[] = "This is a test string";
  const char str2[] = "";

  s21_strncpy(str1, str2, s21_strlen(str2) + 1);
  strncpy(str1_copy, str2, s21_strlen(str2) + 1);
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(strncpy_3) {
  char str1[256];
  char str1_copy[256];
  const char str2[] = "This is a test string";

  s21_strncpy(str1, str2, strlen(str2) + 1);
  strncpy(str1_copy, str2, strlen(str2) + 1);
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(strncpy_4) {
  char str1[] = "This is a test string";
  char str1_copy[] = "This is a test string";
  const char str2[] = "This is a test string ";

  s21_strncpy(str1, str2, 1);
  strncpy(str1_copy, str2, 1);
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(strncpy_5) {
  char str1[] = "123456789";
  char str1_copy[] = "123456789";
  const char str2[] = "abcdef";

  s21_strncpy(str1, str2, 3);
  strncpy(str1_copy, str2, 3);
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(strncpy_6) {
  char str1[] = "123456789";
  char str1_copy[] = "123456789";
  const char str2[] = "abcdef";

  s21_strncpy(str1, str2, strlen(str2) + 1);
  strncpy(str1_copy, str2, strlen(str2) + 1);
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(strncpy_7) {
  const char str1[] = "This is a test string";
  char str2[] = "test";
  char str2_copy[] = "test";

  s21_strncpy(str2, str1, strlen(str2));
  strncpy(str2_copy, str1, strlen(str2));
  ck_assert_str_eq(str2, str2_copy);
}
END_TEST

START_TEST(strncpy_8) {
  char str1[] = "\0\0\0";
  char str1_copy[] = "\0\0\0";
  const char str2[] = "\0";

  s21_strncpy(str1, str2, 1);
  strncpy(str1, str2, 1);
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(strncpy_9) {
  char str1[] = "Hello, world!";
  char str1_copy[] = "Hello, world!";
  const char str2[] = "test";

  s21_strncpy(str1, str2, 1);
  strncpy(str1_copy, str2, 1);
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(strncpy_10) {
  char str1[] = "This is a test string";
  char str1_copy[] = "This is a test string";
  const char str2[] = "test";

  s21_strncpy((str1 + 10), str2, strlen(str2) + 1);
  strncpy((str1_copy + 10), str2, strlen(str2) + 1);
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

extern TCase *tcase_s21_strncpy(void);

TCase *tcase_s21_strncpy(void) {
  TCase *tcase = tcase_create("s21_strncpy");
  tcase_add_test(tcase, test_s21_strncpy_normal);
  tcase_add_test(tcase, test_s21_strncpy_n_zero);
  tcase_add_test(tcase, test_s21_strncpy_overflow);
  tcase_add_test(tcase, test_s21_strncpy_empty);
  tcase_add_test(tcase, test_s21_strncpy_empty_src);
  tcase_add_test(tcase, test_s21_strncpy_src_shorter_than_n);
  tcase_add_test(tcase, test_s21_strncpy_src_same_length_as_n);
  tcase_add_test(tcase, test_s21_strncpy_src_longer_than_n);
  tcase_add_test(tcase, test_s21_strncpy_dest_size_is_n);
  tcase_add_test(tcase, test_s21_strncpy_dest_size_less_than_n);
  tcase_add_test(tcase, test_s21_strncpy_dest_size_less_than_n);
  tcase_add_test(tcase, test_s21_strncpy_dest_size_greater_than_n);
  tcase_add_test(tcase, s21_strncpy_test_terminating);
  tcase_add_test(tcase, s21_strncpy_test_crush);
  tcase_add_test(tcase, strncpy_1);
  tcase_add_test(tcase, strncpy_2);
  tcase_add_test(tcase, strncpy_3);
  tcase_add_test(tcase, strncpy_4);
  tcase_add_test(tcase, strncpy_5);
  tcase_add_test(tcase, strncpy_6);
  tcase_add_test(tcase, strncpy_7);
  tcase_add_test(tcase, strncpy_8);
  tcase_add_test(tcase, strncpy_9);
  tcase_add_test(tcase, strncpy_10);

  return tcase;
}
