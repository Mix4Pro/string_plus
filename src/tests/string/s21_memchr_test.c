#include <string.h>

#include "../../s21_string.h"
#include "string_suite.h"

START_TEST(memchr_1) {
  const char str[] = "This is a test string";
  char c = 's';
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, 10),
                   memchr((const void *)str, (int)c, 10));
}
END_TEST

START_TEST(memchr_2) {
  const char str[] = "0123456789";
  char c = '5';
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, 6),
                   memchr((const void *)str, (int)c, 6));
}
END_TEST

START_TEST(memchr_3) {
  const char str[] = "Hello, world!";
  char c = 'z';
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, strlen(str)),
                   memchr((const void *)str, (int)c, strlen(str)));
}
END_TEST

START_TEST(memchr_4) {
  const char str[] = "This is a test string";
  char c = 's';

  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, 1),
                   memchr((const void *)str, (int)c, 1));
}
END_TEST

START_TEST(memchr_5) {
  const char str[] = "\0";
  char c = 's';
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, 2),
                   memchr((const void *)str, (int)c, 2));
}
END_TEST

START_TEST(memchr_6) {
  const char str[] = "\0\0\0";
  char c = '\0';
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, 2),
                   memchr((const void *)str, (int)c, 2));
}
END_TEST

START_TEST(memchr_7) {
  const char str[] = "school 21";
  char c = ' ';
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, 8),
                   memchr((const void *)str, (int)c, 8));
}
END_TEST

START_TEST(memchr_8) {
  const char str[30] = "\0school 21";
  char c = '1';
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, 20),
                   memchr((const void *)str, (int)c, 20));
}
END_TEST

START_TEST(memchr_9) {
  const char str[] = "Hello, world!";
  char c = 'H';
  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, 0),
                   memchr((const void *)str, (int)c, 0));
}
END_TEST

START_TEST(memchr_10) {
  const char str[] = "AAAAAAAAAAAAAAAAAA!";
  char c = 'A';

  ck_assert_ptr_eq(s21_memchr((const void *)str, (int)c, 5),
                   memchr((const void *)str, (int)c, 5));
}
END_TEST

extern TCase *tcase_s21_memchr(void);

TCase *tcase_s21_memchr(void) {
  TCase *tcase = tcase_create("s21_memchr");
  tcase_add_test(tcase, memchr_1);
  tcase_add_test(tcase, memchr_2);
  tcase_add_test(tcase, memchr_3);
  tcase_add_test(tcase, memchr_4);
  tcase_add_test(tcase, memchr_5);
  tcase_add_test(tcase, memchr_6);
  tcase_add_test(tcase, memchr_7);
  tcase_add_test(tcase, memchr_8);
  tcase_add_test(tcase, memchr_9);
  tcase_add_test(tcase, memchr_10);

  return tcase;
}
