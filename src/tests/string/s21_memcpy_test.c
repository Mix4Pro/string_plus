#include <string.h>

#include "../../s21_string.h"
#include "string_suite.h"

START_TEST(memcpy_1) {
  char str1[] = "This is a test string";
  char str1_copy[] = "This is a test string";
  const char str2[] = "This is a test string";

  s21_memcpy((void *)str1, (const void *)str2, s21_strlen(str1));
  memcpy((void *)str1_copy, (const void *)str2, s21_strlen(str1));
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(memcpy_2) {
  char str1[] = "This is a test string";
  char str1_copy[] = "This is a test string";
  const char str2[] = "";

  s21_memcpy((void *)str1, (const void *)str2, s21_strlen(str2));
  memcpy((void *)str1_copy, (const void *)str2, s21_strlen(str2));
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(memcpy_3) {
  char str1[256];
  char str1_copy[256];
  const char str2[] = "This is a test string";

  s21_memcpy((void *)str1, (const void *)str2, s21_strlen(str2) + 1);
  memcpy((void *)str1_copy, (const void *)str2, s21_strlen(str2) + 1);
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(memcpy_4) {
  char str1[] = "This is a test string";
  char str1_copy[] = "This is a test string";
  const char str2[] = "This is a test string";

  s21_memcpy((void *)str1, (const void *)str2, 0);
  memcpy((void *)str1_copy, (const void *)str2, 0);
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(memcpy_5) {
  char str1[] = "123456789";
  char str1_copy[] = "123456789";
  const char str2[] = "abcdef";

  s21_memcpy((void *)str1, (const void *)str2, 3);
  memcpy((void *)str1_copy, (const void *)str2, 3);
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(memcpy_6) {
  char str1[] = "123456789";
  char str1_copy[] = "123456789";
  const char str2[] = "abcdef";

  s21_memcpy((void *)str1, (const void *)str2, s21_strlen(str2));
  memcpy((void *)str1_copy, (const void *)str2, s21_strlen(str2));
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(memcpy_7) {
  const char str1[] = "This is a test string";
  char str2[] = "test";
  char str2_copy[] = "test";

  s21_memcpy((void *)str2, (const void *)str1, s21_strlen(str2));
  memcpy((void *)str2_copy, (const void *)str1, s21_strlen(str2));
  ck_assert_str_eq(str2, str2_copy);
}
END_TEST

START_TEST(memcpy_8) {
  char str1[] = "\0\0\0";
  char str1_copy[] = "\0\0\0";
  const char str2[] = "\0";

  s21_memcpy((void *)str1, (const void *)str2, 1);
  memcpy((void *)str1_copy, (const void *)str2, 1);
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(memcpy_9) {
  char str1[] = "Hello, world!";
  char str1_copy[] = "Hello, world!";
  const char str2[] = "test";
  s21_memcpy((void *)str1, (const void *)str2, 1);
  memcpy((void *)str1_copy, (const void *)str2, 1);
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

START_TEST(memcpy_10) {
  char str1[] = "This is a test string";
  char str1_copy[] = "This is a test string";
  const char str2[] = "test";

  s21_memcpy((void *)(str1 + 10), (const void *)str2, strlen(str2));
  memcpy((void *)(str1_copy + 10), (const void *)str2, strlen(str2));
  ck_assert_str_eq(str1, str1_copy);
}
END_TEST

extern TCase *tcase_s21_memcpy(void);

TCase *tcase_s21_memcpy(void) {
  TCase *tcase = tcase_create("s21_memcpy");
  tcase_add_test(tcase, memcpy_1);
  tcase_add_test(tcase, memcpy_2);
  tcase_add_test(tcase, memcpy_3);
  tcase_add_test(tcase, memcpy_4);
  tcase_add_test(tcase, memcpy_5);
  tcase_add_test(tcase, memcpy_6);
  tcase_add_test(tcase, memcpy_7);
  tcase_add_test(tcase, memcpy_8);
  tcase_add_test(tcase, memcpy_9);
  tcase_add_test(tcase, memcpy_10);

  return tcase;
}
