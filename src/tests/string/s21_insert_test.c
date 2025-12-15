#include <string.h>

#include "../../s21_string.h"
#include "string_suite.h"

START_TEST(test_s21_insert_normal) {
  char *src = "Hello World";
  char *str = "Awesome ";
  s21_size_t start_index = 6;
  char *expected = "Hello Awesome World";
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_at_start) {
  char *src = "World";
  char *str = "Hello ";
  s21_size_t start_index = 0;
  char *expected = "Hello World";
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_at_end) {
  char *src = "Hello";
  char *str = " World";
  s21_size_t start_index = 5;
  char *expected = "Hello World";
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_null_src) {
  char *src = NULL;
  char *str = "Hello";
  s21_size_t start_index = 0;
  ck_assert_ptr_eq(s21_insert(src, str, start_index), NULL);
}
END_TEST

START_TEST(test_s21_insert_null_str) {
  char *src = "Hello";
  char *str = NULL;
  s21_size_t start_index = 0;
  ck_assert_ptr_eq(s21_insert(src, str, start_index), NULL);
}
END_TEST

START_TEST(test_s21_insert_start_index_out_of_bounds) {
  char *src = "Hello";
  char *str = "World";
  s21_size_t start_index = 10;
  ck_assert_ptr_eq(s21_insert(src, str, start_index), NULL);
}
END_TEST

START_TEST(test_s21_insert_empty_strings) {
  char *src = "";
  char *str = "";
  s21_size_t start_index = 0;
  char *expected = "";
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

extern TCase *tcase_s21_insert(void);

TCase *tcase_s21_insert(void) {
  TCase *tcase = tcase_create("s21_insert");
  tcase_add_test(tcase, test_s21_insert_normal);
  tcase_add_test(tcase, test_s21_insert_at_start);
  tcase_add_test(tcase, test_s21_insert_at_end);
  tcase_add_test(tcase, test_s21_insert_null_src);
  tcase_add_test(tcase, test_s21_insert_null_str);
  tcase_add_test(tcase, test_s21_insert_start_index_out_of_bounds);
  tcase_add_test(tcase, test_s21_insert_empty_strings);
  return tcase;
}