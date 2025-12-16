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

extern TCase *tcase_s21_strerror(void);

TCase *tcase_s21_strerror(void) {
  TCase *tcase = tcase_create("s21_strerror");
  tcase_add_test(tcase, test_s21_strerror_normal);

  return tcase;
}
