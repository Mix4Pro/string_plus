#include <string.h>

#include "../../s21_string.h"
#include "string_suite.h"

START_TEST(memset_1) {
  char str[] = "This is a test string";
  char str_copy[] = "This is a test string";
  char c = 's';

  s21_memset((void *)str, (int)c, 10);
  memset((void *)str_copy, (int)c, 10);
  ck_assert_str_eq(str, str_copy);
}
END_TEST

START_TEST(memset_2) {
  char str[] = "0123456789";
  char str_copy[] = "0123456789";
  char c = '5';

  s21_memset((void *)str, (int)c, 6);
  memset((void *)str_copy, (int)c, 6);
  ck_assert_str_eq(str, str_copy);
}
END_TEST

START_TEST(memset_3) {
  char str[] = "Hello, world!";
  char str_copy[] = "Hello, world!";
  char c = 'z';

  s21_memset((void *)str_copy, (int)c, strlen(str));
  memset((void *)str, (int)c, strlen(str));
  ck_assert_str_eq(str, str_copy);
}
END_TEST

START_TEST(memset_4) {
  char str[] = "This is a test string";
  char str_copy[] = "This is a test string";
  char c = 's';

  s21_memset((void *)str, (int)c, 1);
  memset((void *)str_copy, (int)c, 1);
  ck_assert_str_eq(str, str_copy);
}
END_TEST

START_TEST(memset_5) {
  char str[] = "\0";
  char str_copy[] = "\0";
  char c = 's';

  s21_memset((void *)str, (int)c, 1);
  memset((void *)str_copy, (int)c, 1);
  ck_assert_str_eq(str, str_copy);
}
END_TEST

START_TEST(memset_6) {
  char str[] = "\0\0\0";
  char str_copy[] = "\0\0\0";
  char c = '\0';

  s21_memset((void *)str, (int)c, 1);
  memset((void *)str_copy, (int)c, 1);
  ck_assert_str_eq(str, str_copy);
}
END_TEST

START_TEST(memset_7) {
  char str[] = "school 21";
  char str_copy[] = "school 21";
  char c = ' ';

  s21_memset((void *)str, (int)c, 8);
  memset((void *)str_copy, (int)c, 8);
  ck_assert_str_eq(str, str_copy);
}
END_TEST

START_TEST(memset_8) {
  char str[] = "\0school 21";
  char str_copy[] = "\0school 21";
  char c = '1';

  s21_memset((void *)str, (int)c, 1);
  memset((void *)str_copy, (int)c, 1);
  ck_assert_str_eq(str, str_copy);
}
END_TEST

START_TEST(memset_9) {
  char str[] = "Hello, world!";
  char str_copy[] = "Hello, world!";
  char c = 'h';

  s21_memset((void *)str, (int)c, 1);
  memset((void *)str_copy, (int)c, 1);
  ck_assert_str_eq(str, str_copy);
}
END_TEST

START_TEST(memset_10) {
  char str[] = "AAAAAAAAAAAAAAAAAA!";
  char str_copy[] = "AAAAAAAAAAAAAAAAAA!";
  char c = 'B';

  s21_memset((void *)str, (int)c, 5);
  memset((void *)str_copy, (int)c, 5);
  ck_assert_str_eq(str, str_copy);
}
END_TEST

extern TCase *tcase_s21_memset(void);

TCase *tcase_s21_memset(void) {
  TCase *tcase = tcase_create("s21_memset");
  tcase_add_test(tcase, memset_1);
  tcase_add_test(tcase, memset_2);
  tcase_add_test(tcase, memset_3);
  tcase_add_test(tcase, memset_4);
  tcase_add_test(tcase, memset_5);
  tcase_add_test(tcase, memset_6);
  tcase_add_test(tcase, memset_7);
  tcase_add_test(tcase, memset_8);
  tcase_add_test(tcase, memset_9);
  tcase_add_test(tcase, memset_10);

  return tcase;
}
