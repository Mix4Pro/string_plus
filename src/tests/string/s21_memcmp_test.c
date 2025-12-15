#include <string.h>

#include "../../s21_string.h"
#include "string_suite.h"

int sign_int(int x) { return x > 0 ? 1 : (x < 0 ? -1 : 0); }

START_TEST(memcmp_1) {
  const char str1[] = "This is a test string";
  const char str2[] = "This is a test string";
  int res1 =
      s21_memcmp((const void *)str1, (const void *)str2, s21_strlen(str1));
  int res2 = memcmp((const void *)str1, (const void *)str2, s21_strlen(str1));

  ck_assert_int_eq(sign_int(res1), sign_int(res2));
}
END_TEST

START_TEST(memcmp_2) {
  const char str1[] = "";
  const char str2[] = "";
  int res1 = s21_memcmp(str1, str2, s21_strlen(str1));
  int res2 = memcmp(str1, str2, s21_strlen(str1));

  ck_assert_int_eq(sign_int(res1), sign_int(res2));
}
END_TEST

START_TEST(memcmp_3) {
  const char str1[] = "0123456789";
  const char str2[] = "0123789";
  int res1 = s21_memcmp(str1, str2, 4);
  int res2 = memcmp(str1, str2, 4);

  ck_assert_int_eq(sign_int(res1), sign_int(res2));
}
END_TEST

START_TEST(memcmp_4) {
  const char str1[] = "0123456789";
  const char str2[] = "0123789";
  int res1 = s21_memcmp(str1, str2, s21_strlen(str1));
  int res2 = memcmp(str1, str2, s21_strlen(str1));

  ck_assert_int_eq(sign_int(res1), sign_int(res2));
}
END_TEST

START_TEST(memcmp_5) {
  const char str1[] = "school 21";
  const char str2[] = "Hello";
  int res1 = s21_memcmp(str1, str2, 1);
  int res2 = memcmp(str1, str2, 1);
  ck_assert_int_eq(sign_int(res1), sign_int(res2));
  ck_assert_int_eq(sign_int(res1), sign_int(res2));
}
END_TEST

START_TEST(memcmp_6) {
  const char str1[] = "Hello";
  const char str2[] = "school 21";
  int res1 = s21_memcmp(str1, str2, 1);
  int res2 = memcmp(str1, str2, 1);

  ck_assert_int_eq(sign_int(res1), sign_int(res2));
}
END_TEST

START_TEST(memcmp_7) {
  const char str1[20] = "";
  const char str2[20] = "school 21";
  int res1 = s21_memcmp(str1, str2, 15);
  int res2 = memcmp(str1, str2, 15);

  ck_assert_int_eq(sign_int(res1), sign_int(res2));
}
END_TEST

START_TEST(memcmp_8) {
  const char str1[] = "Hello";
  const char str2[] = "";
  int res1 = s21_memcmp(str1, str2, 1);
  int res2 = memcmp(str1, str2, 1);
  ck_assert_int_eq(sign_int(res1), sign_int(res2));
}
END_TEST

START_TEST(memcmp_9) {
  const char str1[] = "Hello";
  const char str2[] = "";
  int res1 = s21_memcmp(str1, str2, 1);
  int res2 = memcmp(str1, str2, 1);

  ck_assert_int_eq(sign_int(res1), sign_int(res2));
}
END_TEST

START_TEST(memcmp_10) {
  const char str1[256] = "6368457857979094678478";
  const char str2[256] = "1242345384594503486734";
  int res1 = s21_memcmp(str1, str2, 256);
  int res2 = memcmp(str1, str2, 256);
  ck_assert_int_eq(sign_int(res1), sign_int(res2));
}
END_TEST

START_TEST(memcmp_11) {
  const char *str1 = NULL;
  const char str2[] = "1242345384594503486734";
  int res1 = s21_memcmp(str1, str2, 1);

  ck_assert_int_eq(sign_int(res1), -1);
}
END_TEST

START_TEST(memcmp_12) {
  const char str1[] = "1242345384594503486734";
  const char *str2 = NULL;
  int res1 = s21_memcmp(str1, str2, 1);

  ck_assert_int_eq(sign_int(res1), 1);
}
END_TEST

extern TCase *tcase_s21_memcmp(void);

TCase *tcase_s21_memcmp(void) {
  TCase *tcase = tcase_create("s21_memcmp");
  tcase_add_test(tcase, memcmp_1);
  tcase_add_test(tcase, memcmp_2);
  tcase_add_test(tcase, memcmp_3);
  tcase_add_test(tcase, memcmp_4);
  tcase_add_test(tcase, memcmp_5);
  tcase_add_test(tcase, memcmp_6);
  tcase_add_test(tcase, memcmp_7);
  tcase_add_test(tcase, memcmp_8);
  tcase_add_test(tcase, memcmp_9);
  tcase_add_test(tcase, memcmp_10);
  tcase_add_test(tcase, memcmp_11);
  tcase_add_test(tcase, memcmp_12);

  return tcase;
}
