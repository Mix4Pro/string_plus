#include <string.h>

#include "../../s21_string.h"
#include "string_suite.h"

START_TEST(test_s21_strerror_normal) {
  for (int i = 0; i < 40; i++) {
    char *s21_error = s21_strerror(i);
    char *std_error = strerror(i);
    ck_assert_str_eq(s21_error, std_error);
  }
}
END_TEST

// START_TEST(test_s21_strerror_unknown) {
//   int unknown_error = 999;
//   char *s21_error = s21_strerror(unknown_error);
//   char *std_error = strerror(unknown_error);
//   ck_assert_str_eq(s21_error, std_error);
// }
// END_TEST

// START_TEST(test_s21_strerror_negative) {
//   int negative_error = -1;
//   char *s21_error = s21_strerror(negative_error);
//   char *std_error = strerror(negative_error);
//   ck_assert_str_eq(s21_error, std_error);
// }
// END_TEST

// START_TEST(test_s21_strerror_zero) {
//   int zero_error = 0;
//   char *s21_error = s21_strerror(zero_error);
//   char *std_error = strerror(zero_error);
//   ck_assert_str_eq(s21_error, std_error);
// }
// END_TEST

// START_TEST(test_s21_strerror_max) {
//   int max_error = 255;
//   char *s21_error = s21_strerror(max_error);
//   char *std_error = strerror(max_error);
//   ck_assert_str_eq(s21_error, std_error);
// }
// END_TEST

extern TCase *tcase_s21_strerror(void);

TCase *tcase_s21_strerror(void) {
  TCase *tcase = tcase_create("s21_strerror");
  tcase_add_test(tcase, test_s21_strerror_normal);
  // tcase_add_test(tcase, test_s21_strerror_unknown);
  // tcase_add_test(tcase, test_s21_strerror_negative);
  // tcase_add_test(tcase, test_s21_strerror_zero);
  // tcase_add_test(tcase, test_s21_strerror_max);

  return tcase;
}
