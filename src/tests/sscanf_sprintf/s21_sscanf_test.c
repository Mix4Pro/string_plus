#include <string.h>

#include "../../s21_string.h"
#include "sscanf_sprintf_suite.h"

START_TEST(test_char_basic) {
  char c1, c2;
  int r1 = sscanf("a", "%c", &c1);
  int r2 = s21_sscanf("a", "%c", &c2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(test_char_space) {
  char c1, c2;
  int r1 = sscanf(" ", "%c", &c1);
  int r2 = s21_sscanf(" ", "%c", &c2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(test_int_positive) {
  int i1, i2;
  int r1 = sscanf("123", "%d", &i1);
  int r2 = s21_sscanf("123", "%d", &i2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(test_int_negative) {
  int i1, i2;
  int r1 = sscanf("-456", "%d", &i1);
  int r2 = s21_sscanf("-456", "%d", &i2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(test_int_with_plus) {
  int i1, i2;
  int r1 = sscanf("+789", "%d", &i1);
  int r2 = s21_sscanf("+789", "%d", &i2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(test_int_with_spaces) {
  int i1, i2;
  int r1 = sscanf("  123  ", "%d", &i1);
  int r2 = s21_sscanf("  123  ", "%d", &i2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(test_int_multiple) {
  int x1, y1, x2, y2;
  int r1 = sscanf("123 456", "%d %d", &x1, &y1);
  int r2 = s21_sscanf("123 456", "%d %d", &x2, &y2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
}
END_TEST

START_TEST(test_i_decimal) {
  int i1, i2;
  int r1 = sscanf("123", "%i", &i1);
  int r2 = s21_sscanf("123", "%i", &i2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(test_i_octal) {
  int i1, i2;
  int r1 = sscanf("0123", "%i", &i1);
  int r2 = s21_sscanf("0123", "%i", &i2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(test_i_hex) {
  int i1, i2;
  int r1 = sscanf("0x1A", "%i", &i1);
  int r2 = s21_sscanf("0x1A", "%i", &i2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(test_i_hex_uppercase) {
  int i1, i2;
  int r1 = sscanf("0X2B", "%i", &i1);
  int r2 = s21_sscanf("0X2B", "%i", &i2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(test_i_negative_octal) {
  int i1, i2;
  int r1 = sscanf("-0123", "%i", &i1);
  int r2 = s21_sscanf("-0123", "%i", &i2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(test_i_negative_hex) {
  int i1, i2;
  int r1 = sscanf("-0x1F", "%i", &i1);
  int r2 = s21_sscanf("-0x1F", "%i", &i2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(test_string_basic) {
  char s1[20], s2[20];
  int r1 = sscanf("hello", "%s", s1);
  int r2 = s21_sscanf("hello", "%s", s2);
  ck_assert_int_eq(r1, r2);
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(test_string_with_width) {
  char s1[20], s2[20];
  int r1 = sscanf("hello", "%3s", s1);
  int r2 = s21_sscanf("hello", "%3s", s2);
  ck_assert_int_eq(r1, r2);
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(test_string_multiple) {
  char s1[20], s2[20], s3[20], s4[20];
  int r1 = sscanf("hello world", "%s %s", s1, s2);
  int r2 = s21_sscanf("hello world", "%s %s", s3, s4);
  ck_assert_int_eq(r1, r2);
  ck_assert_str_eq(s1, s3);
  ck_assert_str_eq(s2, s4);
}
END_TEST

START_TEST(test_string_with_leading_spaces) {
  char s1[20], s2[20];
  int r1 = sscanf("   test", "%s", s1);
  int r2 = s21_sscanf("   test", "%s", s2);
  ck_assert_int_eq(r1, r2);
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(test_unsigned_basic) {
  unsigned int u1, u2;
  int r1 = sscanf("123", "%u", &u1);
  int r2 = s21_sscanf("123", "%u", &u2);
  ck_assert_int_eq(r1, r2);
  ck_assert_uint_eq(u1, u2);
}
END_TEST

START_TEST(test_unsigned_with_plus) {
  unsigned int u1, u2;
  int r1 = sscanf("+456", "%u", &u1);
  int r2 = s21_sscanf("+456", "%u", &u2);
  ck_assert_int_eq(r1, r2);
  ck_assert_uint_eq(u1, u2);
}
END_TEST

START_TEST(test_octal_basic) {
  unsigned int o1, o2;
  int r1 = sscanf("123", "%o", &o1);
  int r2 = s21_sscanf("123", "%o", &o2);
  ck_assert_int_eq(r1, r2);
  ck_assert_uint_eq(o1, o2);
}
END_TEST

START_TEST(test_octal_with_zero) {
  unsigned int o1, o2;
  int r1 = sscanf("0123", "%o", &o1);
  int r2 = s21_sscanf("0123", "%o", &o2);
  ck_assert_int_eq(r1, r2);
  ck_assert_uint_eq(o1, o2);
}
END_TEST

START_TEST(test_hex_basic) {
  unsigned int h1, h2;
  int r1 = sscanf("1A", "%x", &h1);
  int r2 = s21_sscanf("1A", "%x", &h2);
  ck_assert_int_eq(r1, r2);
  ck_assert_uint_eq(h1, h2);
}
END_TEST

START_TEST(test_hex_with_prefix) {
  unsigned int h1, h2;
  int r1 = sscanf("0x2B", "%x", &h1);
  int r2 = s21_sscanf("0x2B", "%x", &h2);
  ck_assert_int_eq(r1, r2);
  ck_assert_uint_eq(h1, h2);
}
END_TEST

START_TEST(test_hex_uppercase) {
  unsigned int h1, h2;
  int r1 = sscanf("ABCD", "%X", &h1);
  int r2 = s21_sscanf("ABCD", "%X", &h2);
  ck_assert_int_eq(r1, r2);
  ck_assert_uint_eq(h1, h2);
}
END_TEST

START_TEST(test_short_int) {
  short int s1, s2;
  int r1 = sscanf("123", "%hi", &s1);
  int r2 = s21_sscanf("123", "%hi", &s2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(s1, s2);
}
END_TEST

START_TEST(test_long_int) {
  long int l1, l2;
  int r1 = sscanf("123456", "%li", &l1);
  int r2 = s21_sscanf("123456", "%li", &l2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(l1, l2);
}
END_TEST

START_TEST(test_long_long_int) {
  long long int ll1, ll2;
  int r1 = sscanf("123456789", "%lli", &ll1);
  int r2 = s21_sscanf("123456789", "%lli", &ll2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(ll1, ll2);
}
END_TEST

START_TEST(test_unsigned_short) {
  unsigned short us1, us2;
  int r1 = sscanf("123", "%hu", &us1);
  int r2 = s21_sscanf("123", "%hu", &us2);
  ck_assert_int_eq(r1, r2);
  ck_assert_uint_eq(us1, us2);
}
END_TEST

START_TEST(test_unsigned_long) {
  unsigned long ul1, ul2;
  int r1 = sscanf("123456", "%lu", &ul1);
  int r2 = s21_sscanf("123456", "%lu", &ul2);
  ck_assert_int_eq(r1, r2);
  ck_assert_uint_eq(ul1, ul2);
}
END_TEST

START_TEST(test_unsigned_long_long) {
  unsigned long long ull1, ull2;
  int r1 = sscanf("123456789", "%llu", &ull1);
  int r2 = s21_sscanf("123456789", "%llu", &ull2);
  ck_assert_int_eq(r1, r2);
  ck_assert_uint_eq(ull1, ull2);
}
END_TEST

START_TEST(test_pointer_basic) {
  void *p1, *p2;
  int r1 = sscanf("0x1234", "%p", &p1);
  int r2 = s21_sscanf("0x1234", "%p", &p2);
  ck_assert_int_eq(r1, r2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(test_pointer_without_prefix) {
  void *p1, *p2;
  int r1 = sscanf("ABCD", "%p", &p1);
  int r2 = s21_sscanf("ABCD", "%p", &p2);
  ck_assert_int_eq(r1, r2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(test_mixed_types) {
  int i1, i2;
  char s1[20], s2[20];
  int r1 = sscanf("123 hello", "%d %s", &i1, s1);
  int r2 = s21_sscanf("123 hello", "%d %s", &i2, s2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(i1, i2);
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(test_no_space_between_values) {
  long long a1, a2, c1, c2;
  char b1, b2, d1, d2;
  int r1 = sscanf("100500-600+700+400", "%lli%c%lli%c", &a1, &b1, &c1, &d1);
  int r2 = s21_sscanf("100500-600+700+400", "%lli%c%lli%c", &a2, &b2, &c2, &d2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_literal_match) {
  int i1, i2;
  int r1 = sscanf("value:123", "value:%d", &i1);
  int r2 = s21_sscanf("value:123", "value:%d", &i2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(test_literal_mismatch) {
  int i1 = 0, i2 = 0;
  int r1 = sscanf("wrong:123", "value:%d", &i1);
  int r2 = s21_sscanf("wrong:123", "value:%d", &i2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_whitespace_in_format) {
  int i1, i2, j1, j2;
  int r1 = sscanf("123    456", "%d    %d", &i1, &j1);
  int r2 = s21_sscanf("123    456", "%d    %d", &i2, &j2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(j1, j2);
}
END_TEST

START_TEST(test_partial_match) {
  int i1, i2;
  char c1, c2;
  int r1 = sscanf("123abc", "%d%c", &i1, &c1);
  int r2 = s21_sscanf("123abc", "%d%c", &i2, &c2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(test_format_longer_than_input) {
  int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
  int r1 = sscanf("123", "%d %d", &i1, &j1);
  int r2 = s21_sscanf("123", "%d %d", &i2, &j2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(test_invalid_number) {
  int i1 = 0, i2 = 0;
  int r1 = sscanf("abc", "%d", &i1);
  int r2 = s21_sscanf("abc", "%d", &i2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_multiple_signs) {
  int i1 = 0, i2 = 0;
  int r1 = sscanf("++123", "%d", &i1);
  int r2 = s21_sscanf("++123", "%d", &i2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_octal_zero_prefix) {
  int i1, i2;
  int r1 = sscanf("0777", "%i", &i1);
  int r2 = s21_sscanf("0777", "%i", &i2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(test_all_modifiers_with_d) {
  short s1, s2;
  long l1, l2;
  long long ll1, ll2;

  int r1 = sscanf("100", "%hd", &s1);
  int r2 = s21_sscanf("100", "%hd", &s2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(s1, s2);

  r1 = sscanf("200", "%ld", &l1);
  r2 = s21_sscanf("200", "%ld", &l2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(l1, l2);

  r1 = sscanf("300", "%lld", &ll1);
  r2 = s21_sscanf("300", "%lld", &ll2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(ll1, ll2);
}
END_TEST

START_TEST(test_hex_with_all_modifiers) {
  unsigned short us1, us2;
  unsigned long ul1, ul2;
  unsigned long long ull1, ull2;

  int r1 = sscanf("FF", "%hx", &us1);
  int r2 = s21_sscanf("FF", "%hx", &us2);
  ck_assert_int_eq(r1, r2);
  ck_assert_uint_eq(us1, us2);

  r1 = sscanf("FFFF", "%lx", &ul1);
  r2 = s21_sscanf("FFFF", "%lx", &ul2);
  ck_assert_int_eq(r1, r2);
  ck_assert_uint_eq(ul1, ul2);

  r1 = sscanf("FFFFFFFF", "%llx", &ull1);
  r2 = s21_sscanf("FFFFFFFF", "%llx", &ull2);
  ck_assert_int_eq(r1, r2);
  ck_assert_uint_eq(ull1, ull2);
}
END_TEST

START_TEST(test_octal_with_modifiers) {
  unsigned short us1, us2;
  unsigned long ul1, ul2;

  int r1 = sscanf("77", "%ho", &us1);
  int r2 = s21_sscanf("77", "%ho", &us2);
  ck_assert_int_eq(r1, r2);
  ck_assert_uint_eq(us1, us2);

  r1 = sscanf("777", "%lo", &ul1);
  r2 = s21_sscanf("777", "%lo", &ul2);
  ck_assert_int_eq(r1, r2);
  ck_assert_uint_eq(ul1, ul2);
}
END_TEST

START_TEST(test_width_exact) {
  char s1[10], s2[10];
  int r1 = sscanf("12345", "%5s", s1);
  int r2 = s21_sscanf("12345", "%5s", s2);
  ck_assert_int_eq(r1, r2);
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(test_multiple_formats) {
  int d1, d2;
  unsigned u1, u2;
  unsigned h1, h2;

  int r1 = sscanf("123 456 0x1A", "%d %u %x", &d1, &u1, &h1);
  int r2 = s21_sscanf("123 456 0x1A", "%d %u %x", &d2, &u2, &h2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(d1, d2);
  ck_assert_uint_eq(u1, u2);
  ck_assert_uint_eq(h1, h2);
}
END_TEST

TCase *tcase_s21_sscanf(void) {
  TCase *tcase = tcase_create("s21_sscanf_comprehensive");

  tcase_add_test(tcase, test_char_basic);
  tcase_add_test(tcase, test_char_space);

  tcase_add_test(tcase, test_int_positive);
  tcase_add_test(tcase, test_int_negative);
  tcase_add_test(tcase, test_int_with_plus);
  tcase_add_test(tcase, test_int_with_spaces);
  tcase_add_test(tcase, test_int_multiple);

  tcase_add_test(tcase, test_i_decimal);
  tcase_add_test(tcase, test_i_octal);
  tcase_add_test(tcase, test_i_hex);
  tcase_add_test(tcase, test_i_hex_uppercase);
  tcase_add_test(tcase, test_i_negative_octal);
  tcase_add_test(tcase, test_i_negative_hex);

  tcase_add_test(tcase, test_string_basic);
  tcase_add_test(tcase, test_string_with_width);
  tcase_add_test(tcase, test_string_multiple);
  tcase_add_test(tcase, test_string_with_leading_spaces);

  tcase_add_test(tcase, test_unsigned_basic);
  tcase_add_test(tcase, test_unsigned_with_plus);

  tcase_add_test(tcase, test_octal_basic);
  tcase_add_test(tcase, test_octal_with_zero);

  tcase_add_test(tcase, test_hex_basic);
  tcase_add_test(tcase, test_hex_with_prefix);
  tcase_add_test(tcase, test_hex_uppercase);

  tcase_add_test(tcase, test_short_int);
  tcase_add_test(tcase, test_long_int);
  tcase_add_test(tcase, test_long_long_int);
  tcase_add_test(tcase, test_unsigned_short);
  tcase_add_test(tcase, test_unsigned_long);
  tcase_add_test(tcase, test_unsigned_long_long);

  tcase_add_test(tcase, test_pointer_basic);
  tcase_add_test(tcase, test_pointer_without_prefix);

  tcase_add_test(tcase, test_mixed_types);
  tcase_add_test(tcase, test_no_space_between_values);
  tcase_add_test(tcase, test_literal_match);
  tcase_add_test(tcase, test_literal_mismatch);
  tcase_add_test(tcase, test_whitespace_in_format);

  tcase_add_test(tcase, test_partial_match);
  tcase_add_test(tcase, test_format_longer_than_input);
  tcase_add_test(tcase, test_invalid_number);
  tcase_add_test(tcase, test_multiple_signs);

  tcase_add_test(tcase, test_octal_zero_prefix);
  tcase_add_test(tcase, test_all_modifiers_with_d);
  tcase_add_test(tcase, test_hex_with_all_modifiers);
  tcase_add_test(tcase, test_octal_with_modifiers);
  tcase_add_test(tcase, test_width_exact);
  tcase_add_test(tcase, test_multiple_formats);

  return tcase;
}
