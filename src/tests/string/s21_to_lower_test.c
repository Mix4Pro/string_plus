#include "../../s21_string.h"
#include "string_suite.h"

START_TEST(test_s21_to_lower_normal) {
  char *str = "HELLO WORLD";
  char *expected = "hello world";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_empty_string) {
  char *str = "";
  char *expected = "";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_null_input) {
  char *str = NULL;
  ck_assert_ptr_eq(s21_to_lower(str), NULL);
}
END_TEST

START_TEST(test_s21_to_lower_all_uppercase) {
  char *str = "hello world";
  char *expected = "hello world";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

extern TCase *tcase_s21_to_lower(void);

TCase *tcase_s21_to_lower(void) {
  TCase *tcase = tcase_create("s21_to_lower");
  tcase_add_test(tcase, test_s21_to_lower_normal);
  tcase_add_test(tcase, test_s21_to_lower_empty_string);
  tcase_add_test(tcase, test_s21_to_lower_null_input);
  tcase_add_test(tcase, test_s21_to_lower_all_uppercase);
  return tcase;
}