#ifndef STRING_SUITE_H
#define STRING_SUITE_H

#include <check.h>


#include "s21_insert_test.c"
#include "s21_memchr_test.c"
#include "s21_memcmp_test.c"
#include "s21_memcpy_test.c"
#include "s21_memset_test.c"
#include "s21_strcspn_test.c"
#include "s21_strerror_test.c"
#include "s21_strlen_test.c"
#include "s21_strncat_test.c"
#include "s21_strncmp_test.c"
#include "s21_strncpy_test.c"
#include "s21_strpbrk_test.c"
#include "s21_strrchr_test.c"
#include "s21_strstr_test.c"
#include "s21_strtok_test.c"
#include "s21_to_lower_test.c"
#include "s21_to_upper_test.c"
#include "s21_trim_test.c"

Suite *string_suite(void);

#endif
