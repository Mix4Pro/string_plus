#include "sscanf_sprintf_suite.h"

int main(void) {
  int failed_count = 0;
  Suite *s = sscanf_sprintf_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed_count == 0 ? 0 : 1;
}

Suite *sscanf_sprintf_suite(void) {
  Suite *s = suite_create("Sscanf sprintf");

  suite_add_tcase(s, tcase_s21_sscanf());
  suite_add_tcase(s, tcase_s21_sprintf());

  return s;
}
