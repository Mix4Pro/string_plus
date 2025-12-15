#include <string.h>

#include "../../s21_string.h"
#include "sscanf_sprintf_suite.h"

START_TEST(sprintf_d_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 123;
  char *format = "|%d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = INT_MIN;
  char *format = "|%d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = INT_MAX;
  char *format = "|%+d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_4) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = INT_MAX;
  char *format = "|% d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_5) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 0;
  char *format = "|%+d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_6) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 5346457;
  char *format = "|%015d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_7) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 6878;
  char *format = "|%1d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_8) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = -315;
  char *format = "|%4d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_9) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = -14566;
  char *format = "|%.1d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_10) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 56368;
  char *format = "|%.10d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_11) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = -67567;
  char *format = "|%.6d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_12) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 99999;
  char *format = "|%015.10d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_13) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = -131135;
  int y = 12;
  char *format = "|%.*d|\n";
  int res1 = s21_sprintf(str1, format, y, x);
  int res2 = sprintf(str2, format, y, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_14) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 354634;
  int y = 12;
  int z = 16;
  char *format = "|%*.*d|\n";
  int res1 = s21_sprintf(str1, format, z, y, x);
  int res2 = sprintf(str2, format, z, y, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_15) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 354634;
  int y = 12;
  int z = 16;
  char *format = "|%-*.*d|\n";
  int res1 = s21_sprintf(str1, format, z, y, x);
  int res2 = sprintf(str2, format, z, y, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_16) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 354634;
  char *format = "|%+-020.15d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_17) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 354634;
  char *format = "|%+-015.20d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  unsigned int x = UINT_MAX;
  char *format = "|%+-015.20u|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  unsigned long int x = ULLONG_MAX;
  char *format = "|%+ 15.20lu|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ld_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  long int x = LONG_MAX;
  char *format = "|%+-015.20ld|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ld_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  long int x = LLONG_MIN;
  char *format = "|%ld|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hd_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  short int x = SHRT_MIN;
  char *format = "|%+-015.20hd|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_i_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 12345678;
  char *format = "|%+-015.20i|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 12345678;
  char *format = "|%o|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 12345678;
  char *format = "|%+-15.20o|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 12345678;
  char *format = "|%#o|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o_4) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 12345678;
  char *format = "|%#+-15.9o|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_o_5) {
  char str1[1024] = "";
  char str2[1024] = "";
  unsigned int x = 0;
  char *format = "|%o|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_lo_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  long int x = 84518;
  char *format = "|%lo|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 12345678;
  char *format = "|%#x|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 12345678;
  char *format = "|%x|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  unsigned int x = UINT_MAX;
  char *format = "|%+-20.15x|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_4) {
  char str1[1024] = "";
  char str2[1024] = "";
  unsigned int x = UINT_MAX;
  char *format = "|%+ 20.15x|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_X_1) {
  char str1[1024] = "test ";
  char str2[1024] = "test ";
  int x = 0xF12443;
  char *format = "|%X|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_X_2) {
  char str1[1024] = "fffff ";
  char str2[1024] = "fffff ";
  int x = 0xf12443;
  char *format = "|%015X|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_X_3) {
  char str1[1024] = "fffff ";
  char str2[1024] = "fffff ";
  int x = 0;
  char *format = "|%X|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_lx_1) {
  char str1[1024] = "fffff ";
  char str2[1024] = "fffff ";
  long int x = 15;
  char *format = "|%lx|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_lX_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  unsigned long int x = (long int)LLONG_MIN;
  char *format = "|%lX|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  char c = '1';
  char *format = "|%c|\n";
  int res1 = s21_sprintf(str1, format, c);
  int res2 = sprintf(str2, format, c);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  char c = '\0';
  char *format = "%c\n";
  int res1 = s21_sprintf(str1, format, c);
  int res2 = sprintf(str2, format, c);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  char c = 'A';
  char *format = "|%lc|\n";
  int res1 = s21_sprintf(str1, format, (unsigned long)c);
  int res2 = sprintf(str2, format, (unsigned long)c);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_lc_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  wchar_t ch = L'1';
  char *format = "|%lc|\n";
  int res1 = s21_sprintf(str1, format, (unsigned long)ch);
  int res2 = sprintf(str2, format, (unsigned long)ch);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "\0";
  char *format = "|%s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *format = "|%s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *format = "|%.2s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_4) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *format = "|%.*s|\n";
  int res1 = s21_sprintf(str1, format, 3, str3);
  int res2 = sprintf(str2, format, 3, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_5) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *format = "|%10.5s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_6) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *format = "|%10.2s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_7) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *format = "|%10.0s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_8) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *format = "|%-5s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_9) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = NULL;
  char *format = "|%s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_10) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = NULL;
  char *format = "|%10.5s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_11) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = NULL;
  char *format = "|%-10.6s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ls_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  wchar_t *str3 = NULL;
  char *format = "|%-10.6ls|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ls_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  wchar_t *str3 = L"";
  char *format = "|%ls|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ls_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  wchar_t *str3 = L"wchar string test";
  char *format = "|%ls|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_p_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *format = "|%p|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_p_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *format = "|%p|\n";
  char *ptr = NULL;
  int res1 = s21_sprintf(str1, format, ptr);
  int res2 = sprintf(str2, format, ptr);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_p_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *format = "|%+-15.6p|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_p_4) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *format = "|%+-20.p|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_n_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  int count1;
  int count2;
  char *format = "|%+-20.p%n|\n";
  int res1 = s21_sprintf(str1, format, str3, &count1);
  int res2 = sprintf(str2, format, str3, &count2);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_n_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  int count1;
  int count2;
  char *format = "|%n|\n";
  int res1 = s21_sprintf(str1, format, &count1);
  int res2 = sprintf(str2, format, &count2);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_per_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *format = "|%%\n%d|\n";
  int res1 = s21_sprintf(str1, format, 1);
  int res2 = sprintf(str2, format, 1);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_per_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *format = "|%%%%%% %d|\n";
  int res1 = s21_sprintf(str1, format, 1);
  int res2 = sprintf(str2, format, 1);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 123.34634;
  char *format = "|%f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = -4534123.34634;
  char *format = "|%f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 0.0;
  char *format = "|%f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_4) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 9123487;
  char *format = "|%#.0f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_5) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 9123487.635;
  char *format = "|%.0f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_6) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = -69678363.135768656;
  char *format = "|%15.0f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_7) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = -69678363.135768656;
  char *format = "|%*.*f|\n";
  int res1 = s21_sprintf(str1, format, 20, 2, x);
  int res2 = sprintf(str2, format, 20, 2, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_8) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 0.00005;
  char *format = "|%+013f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_9) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 0.0;
  char *format = "|%.0f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_11) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 99934634632.3;
  char *format = "|%-+08.3f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_12) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = -94634.452463574563;
  char *format = "|%+010f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_13) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 0.00000000054524;
  char *format = "|%#+010.f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_14) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 0.00000000054524;
  char *format = "|%#+ 30.10f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_15) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 4.1111e-30;
  char *format = "|%40.35f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_16) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 0.0;
  char *format = "|%.2f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_Lf_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  long double x = 4.1111e-30;
  char *format = "|%+40.35Lf|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_Lf_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  long double x = 3.141592653589793238462643383279502884L;
  char *format = "|%Lf|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_Lf_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  long double x = 3.3489;
  char *format = "|%.3Lf|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_Lf_4) {
  char str1[1024] = "";
  char str2[1024] = "";
  long double x = 9999999.9999999;
  char *format = "|%Lf|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 434561.413;
  char *format = "|%e|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 0.0;
  char *format = "|%8.2e|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = -1245.57685665;
  char *format = "|%+-10.1e|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_4) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 0.57685665;
  char *format = "|%+-30.13e|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_5) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 0.57685665;
  char *format = "|%- 30.13e|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_6) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 0.57685665;
  char *format = "|%0.13e|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_7) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 123;
  char *format = "|%#.0e|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_8) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 123;
  char *format = "|%*.*e|\n";
  int res1 = s21_sprintf(str1, format, 1, 1, x);
  int res2 = sprintf(str2, format, 1, 1, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_9) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 9999999999;
  char *format = "|%e|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_Le_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  long double x = 123e+38;
  char *format = "|%Le|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_Le_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  long double x = 123e-308;
  char *format = "|%Le|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_Le_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  long double x = 3046435466756.36758799090111;
  char *format = "|%30.8Le|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_Le_4) {
  char str1[1024] = "";
  char str2[1024] = "";
  long double x = 0.0;
  char *format = "|%30.8Le|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_E_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 0.57685665;
  char *format = "|%- 30.13E|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_LE_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  long double x = 123e+38;
  char *format = "|%LE|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_LE_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  long double x = 123e-308;
  char *format = "|%LE|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_LE_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  long double x = 3046435466756.36758799090111;
  char *format = "|%30.8LE|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_LE_4) {
  char str1[1024] = "";
  char str2[1024] = "";
  long double x = 0.0;
  char *format = "|%30.8LE|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 45456;
  char *format = "|%-30.8g|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 12345.340000;
  char *format = "|%+#20.10g|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 100000.1;
  char *format = "|% 20.10g|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_4) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 9999999.5;
  char *format = "|%020.15g|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_5) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 1.5;
  char *format = "|%+20.0g|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_6) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 100000.0;
  char *format = "|%#.5g|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_7) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 34253564577.0;
  char *format = "|%g|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_G_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 0.1242353635;
  char *format = "|%G|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_G_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 1352465.5454;
  char *format = "|%G|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_G_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  long double x = NAN;
  char *format = "|%LG|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

#ifndef VALGRIND
START_TEST(sprintf_G_4) {
  char str1[1024] = "";
  char str2[1024] = "";
  long double x = INFINITY;
  char *format = "|%LG|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_G_5) {
  char str1[1024] = "";
  char str2[1024] = "";
  long double x = -INFINITY;
  char *format = "|%+- #100.20LG|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_10) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 99934634632.3;
  char *format = "|%-+15.8f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST
#endif

START_TEST(sprintf_parse_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  long double x = -INFINITY;
  char *format = "|%+- #100.20,LG|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

extern TCase *tcase_s21_sprintf(void);

TCase *tcase_s21_sprintf(void) {
  TCase *tcase = tcase_create("s21_sprintf");
  tcase_add_test(tcase, sprintf_d_1);
  tcase_add_test(tcase, sprintf_d_2);
  tcase_add_test(tcase, sprintf_d_3);
  tcase_add_test(tcase, sprintf_d_4);
  tcase_add_test(tcase, sprintf_d_5);
  tcase_add_test(tcase, sprintf_d_6);
  tcase_add_test(tcase, sprintf_d_7);
  tcase_add_test(tcase, sprintf_d_8);
  tcase_add_test(tcase, sprintf_d_9);
  tcase_add_test(tcase, sprintf_d_10);
  tcase_add_test(tcase, sprintf_d_11);
  tcase_add_test(tcase, sprintf_d_12);
  tcase_add_test(tcase, sprintf_d_13);
  tcase_add_test(tcase, sprintf_d_14);
  tcase_add_test(tcase, sprintf_d_15);
  tcase_add_test(tcase, sprintf_d_16);
  tcase_add_test(tcase, sprintf_d_17);
  tcase_add_test(tcase, sprintf_u_1);
  tcase_add_test(tcase, sprintf_u_2);
  tcase_add_test(tcase, sprintf_ld_1);
  tcase_add_test(tcase, sprintf_ld_2);
  tcase_add_test(tcase, sprintf_hd_1);
  tcase_add_test(tcase, sprintf_i_1);
  tcase_add_test(tcase, sprintf_o_1);
  tcase_add_test(tcase, sprintf_o_2);
  tcase_add_test(tcase, sprintf_o_3);
  tcase_add_test(tcase, sprintf_o_4);
  tcase_add_test(tcase, sprintf_o_5);
  tcase_add_test(tcase, sprintf_lo_1);
  tcase_add_test(tcase, sprintf_x_1);
  tcase_add_test(tcase, sprintf_x_2);
  tcase_add_test(tcase, sprintf_x_3);
  tcase_add_test(tcase, sprintf_x_4);
  tcase_add_test(tcase, sprintf_X_1);
  tcase_add_test(tcase, sprintf_X_2);
  tcase_add_test(tcase, sprintf_X_3);
  tcase_add_test(tcase, sprintf_lx_1);
  tcase_add_test(tcase, sprintf_lX_2);
  tcase_add_test(tcase, sprintf_c_1);
  tcase_add_test(tcase, sprintf_c_2);
  tcase_add_test(tcase, sprintf_c_3);
  tcase_add_test(tcase, sprintf_lc_1);
  tcase_add_test(tcase, sprintf_s_1);
  tcase_add_test(tcase, sprintf_s_2);
  tcase_add_test(tcase, sprintf_s_3);
  tcase_add_test(tcase, sprintf_s_4);
  tcase_add_test(tcase, sprintf_s_5);
  tcase_add_test(tcase, sprintf_s_6);
  tcase_add_test(tcase, sprintf_s_7);
  tcase_add_test(tcase, sprintf_s_8);
  tcase_add_test(tcase, sprintf_s_9);
  tcase_add_test(tcase, sprintf_s_10);
  tcase_add_test(tcase, sprintf_s_11);
  tcase_add_test(tcase, sprintf_s_1);
  tcase_add_test(tcase, sprintf_ls_1);
  tcase_add_test(tcase, sprintf_ls_2);
  tcase_add_test(tcase, sprintf_ls_3);
  tcase_add_test(tcase, sprintf_p_1);
  tcase_add_test(tcase, sprintf_p_2);
  tcase_add_test(tcase, sprintf_p_3);
  tcase_add_test(tcase, sprintf_p_4);
  tcase_add_test(tcase, sprintf_n_1);
  tcase_add_test(tcase, sprintf_n_2);
  tcase_add_test(tcase, sprintf_per_1);
  tcase_add_test(tcase, sprintf_per_2);
  tcase_add_test(tcase, sprintf_f_1);
  tcase_add_test(tcase, sprintf_f_2);
  tcase_add_test(tcase, sprintf_f_3);
  tcase_add_test(tcase, sprintf_f_4);
  tcase_add_test(tcase, sprintf_f_5);
  tcase_add_test(tcase, sprintf_f_6);
  tcase_add_test(tcase, sprintf_f_7);
  tcase_add_test(tcase, sprintf_f_8);
  tcase_add_test(tcase, sprintf_f_9);
  tcase_add_test(tcase, sprintf_f_11);
  tcase_add_test(tcase, sprintf_f_12);
  tcase_add_test(tcase, sprintf_f_13);
  tcase_add_test(tcase, sprintf_f_14);
  tcase_add_test(tcase, sprintf_f_15);
  tcase_add_test(tcase, sprintf_f_16);
  tcase_add_test(tcase, sprintf_Lf_1);
  tcase_add_test(tcase, sprintf_Lf_2);
  tcase_add_test(tcase, sprintf_Lf_3);
  tcase_add_test(tcase, sprintf_Lf_4);
  tcase_add_test(tcase, sprintf_e_1);
  tcase_add_test(tcase, sprintf_e_2);
  tcase_add_test(tcase, sprintf_e_3);
  tcase_add_test(tcase, sprintf_e_4);
  tcase_add_test(tcase, sprintf_e_5);
  tcase_add_test(tcase, sprintf_e_6);
  tcase_add_test(tcase, sprintf_e_7);
  tcase_add_test(tcase, sprintf_e_8);
  tcase_add_test(tcase, sprintf_e_9);
  tcase_add_test(tcase, sprintf_Le_1);
  tcase_add_test(tcase, sprintf_Le_2);
  tcase_add_test(tcase, sprintf_Le_3);
  tcase_add_test(tcase, sprintf_Le_4);
  tcase_add_test(tcase, sprintf_E_1);
  tcase_add_test(tcase, sprintf_LE_1);
  tcase_add_test(tcase, sprintf_LE_2);
  tcase_add_test(tcase, sprintf_LE_3);
  tcase_add_test(tcase, sprintf_LE_4);
  tcase_add_test(tcase, sprintf_g_1);
  tcase_add_test(tcase, sprintf_g_2);
  tcase_add_test(tcase, sprintf_g_3);
  tcase_add_test(tcase, sprintf_g_4);
  tcase_add_test(tcase, sprintf_g_5);
  tcase_add_test(tcase, sprintf_g_6);
  tcase_add_test(tcase, sprintf_g_7);
  tcase_add_test(tcase, sprintf_G_1);
  tcase_add_test(tcase, sprintf_G_2);
  tcase_add_test(tcase, sprintf_G_3);
#ifndef VALGRIND
  tcase_add_test(tcase, sprintf_G_4);
  tcase_add_test(tcase, sprintf_G_5);
  tcase_add_test(tcase, sprintf_f_10);
#endif
  tcase_add_test(tcase, sprintf_parse_1);

  return tcase;
}