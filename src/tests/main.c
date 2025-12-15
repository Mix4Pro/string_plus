#include "../s21_string.h"

int main() {
  char str1[1024] = "";
  char str2[1024] = "";
  char *ch = NULL;
  char *format = "|%p|\n";
  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);

  printf("%d: %s%d: %s", res1, str1, res2, str2);

  return 0;
}