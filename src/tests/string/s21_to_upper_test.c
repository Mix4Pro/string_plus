#include "../../s21_string.h"
#include "string_suite.h"

START_TEST(test_s21_to_upper_normal) {
  char *str = "hello world";
  char *expected = "HELLO WORLD";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_empty_string) {
  char *str = "";
  char *expected = "";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_null_input) {
  char *str = NULL;
  ck_assert_ptr_eq(s21_to_upper(str), NULL);
}
END_TEST

START_TEST(test_s21_to_upper_all_uppercase) {
  char *str = "HELLO WORLD";
  char *expected = "HELLO WORLD";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

extern TCase *tcase_s21_to_upper(void);

TCase *tcase_s21_to_upper(void) {
  TCase *tcase = tcase_create("s21_to_upper");
  tcase_add_test(tcase, test_s21_to_upper_normal);
  tcase_add_test(tcase, test_s21_to_upper_empty_string);
  tcase_add_test(tcase, test_s21_to_upper_null_input);
  tcase_add_test(tcase, test_s21_to_upper_all_uppercase);
  return tcase;
}