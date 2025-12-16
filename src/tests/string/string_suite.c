#include "string_suite.h"

#include <stdlib.h>

int main(void) {
  int failed_count = 0;
  Suite *s = string_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed_count == 0 ? 0 : 1;
}

Suite *string_suite(void) {
  Suite *s = suite_create("String");

  suite_add_tcase(s, tcase_s21_strncpy());
  suite_add_tcase(s, tcase_s21_strcspn());
  suite_add_tcase(s, tcase_s21_strlen());
  suite_add_tcase(s, tcase_s21_strpbrk());
  suite_add_tcase(s, tcase_s21_strrchr());
  suite_add_tcase(s, tcase_s21_strstr());
  suite_add_tcase(s, tcase_s21_strtok());
  suite_add_tcase(s, tcase_s21_strerror());
  suite_add_tcase(s, tcase_s21_to_upper());
  suite_add_tcase(s, tcase_s21_to_lower());
  suite_add_tcase(s, tcase_s21_insert());
  suite_add_tcase(s, tcase_s21_trim());
  suite_add_tcase(s, tcase_s21_memchr());
  suite_add_tcase(s, tcase_s21_memcmp());
  suite_add_tcase(s, tcase_s21_memcpy());
  suite_add_tcase(s, tcase_s21_memset());
  suite_add_tcase(s, tcase_s21_strncat());
  suite_add_tcase(s, tcase_s21_strncmp());

  return s;
}
