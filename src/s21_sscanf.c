#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>

#include "s21_string.h"

static int parse_input(const char *str, const char *format, va_list args);
static void parse_format_specifier(const char **format_ptr, int *width,
                                   int *length_modifier, bool *suppress);
static int parse_value(const char **str_ptr, const char *format_ptr, int width,
                       int length_modifier, va_list args);
static int parse_char(const char **str_ptr, va_list args);
static int parse_int_with_base(const char **str_ptr, int length_modifier, va_list args);
static int parse_int(const char **str_ptr, int length_modifier, va_list args);
static int parse_string(const char **str_ptr, int width, va_list args);
static int parse_unsigned(const char **str_ptr, int length_modifier, va_list args);
static int parse_octal(const char **str_ptr, int length_modifier, va_list args);
static int parse_hex(const char **str_ptr, int length_modifier, va_list args);
static int parse_pointer(const char **str_ptr, va_list args);

// Вспомогательные функции для парсинга чисел
static long long parse_number(const char **str_ptr, int base, int *success);
static unsigned long long parse_unsigned_number(const char **str_ptr, int base, int *success);
static int digit_value(char c);

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int result = parse_input(str, format, args);
  va_end(args);
  return result;
}

static int parse_input(const char *str, const char *format, va_list args) {
  int result = 0;
  const char *str_ptr = str;
  const char *format_ptr = format;

  while (*format_ptr && *str_ptr) {
    if (isspace(*format_ptr)) {
      while (isspace(*format_ptr)) format_ptr++;
      while (isspace(*str_ptr)) str_ptr++;
    } else if (*format_ptr != '%') {
      if (*str_ptr == *format_ptr) {
        str_ptr++;
        format_ptr++;
      } else {
        break;
      }
    } else {
      format_ptr++;
      int width = -1, length_modifier = 0;
      bool suppress = false;
      parse_format_specifier(&format_ptr, &width, &length_modifier, &suppress);
      
      int parsed = parse_value(&str_ptr, format_ptr, width, length_modifier, args);
      if (parsed == 0) {
        break;
      }
      if (!suppress) {
        result += parsed;
      }
      format_ptr++;
    }
  }
  return result;
}

static void parse_format_specifier(const char **format_ptr, int *width,
                                   int *length_modifier, bool *suppress) {
  if (**format_ptr == '*') {
    *suppress = true;
    (*format_ptr)++;
  }
  
  if (isdigit(**format_ptr)) {
    *width = 0;
    while (isdigit(**format_ptr)) {
      *width = *width * 10 + (**format_ptr - '0');
      (*format_ptr)++;
    }
  }
  
  if (**format_ptr == 'h' || **format_ptr == 'l' || **format_ptr == 'L') {
    *length_modifier = **format_ptr;
    (*format_ptr)++;
    if ((**format_ptr == 'h' && *length_modifier == 'h') ||
        (**format_ptr == 'l' && *length_modifier == 'l')) {
      *length_modifier = **format_ptr == 'h' ? 'H' : 'L';
      (*format_ptr)++;
    }
  }
}

static int parse_value(const char **str_ptr, const char *format_ptr, int width,
                       int length_modifier, va_list args) {
  switch (*format_ptr) {
    case 'c':
      return parse_char(str_ptr, args);
    case 'd':
      return parse_int(str_ptr, length_modifier, args);
    case 'i':
      return parse_int_with_base(str_ptr, length_modifier, args);
    case 's':
      return parse_string(str_ptr, width, args);
    case 'u':
      return parse_unsigned(str_ptr, length_modifier, args);
    case 'o':
      return parse_octal(str_ptr, length_modifier, args);
    case 'x':
    case 'X':
      return parse_hex(str_ptr, length_modifier, args);
    case 'p':
      return parse_pointer(str_ptr, args);
    default:
      return 0;
  }
}

static int digit_value(char c) {
  if (c >= '0' && c <= '9') return c - '0';
  if (c >= 'a' && c <= 'f') return c - 'a' + 10;
  if (c >= 'A' && c <= 'F') return c - 'A' + 10;
  return -1;
}

// static long long parse_number(const char **str_ptr, int base, int *success) {
//     const char *p = *str_ptr;
//     long long result = 0;
//     int sign = 1;
//     *success = 0; // явно инициализируем успех

//     if (*p == '-') { sign = -1; p++; }
//     else if (*p == '+') { p++; }

//     int digits_read = 0;
//     while (*p) {
//         int digit = digit_value(*p);
//         if (digit < 0 || digit >= base) break;
//         result = result * base + digit;
//         p++;
//         digits_read++;
//     }

//     if (digits_read > 0) {
//         *success = 1;
//         *str_ptr = p;
//         return result * sign;
//     }
//     return 0;
// }

static long long parse_number(const char **str_ptr, int base, int *success) {
    const char *p = *str_ptr;
    long long result = 0;
    int sign = 1;
    *success = 0;

    // Пропускаем знак
    if (*p == '-') { sign = -1; p++; }
    else if (*p == '+') { p++; }

    int digits_read = 0;
    while (*p) {
        int digit = digit_value(*p);
        if (digit < 0 || digit >= base) break;
        result = result * base + digit;
        p++;
        digits_read++;
    }

    if (digits_read > 0) {
        *success = 1;
        *str_ptr = p; // сдвигаем только если реально что-то считали
        return result * sign;
    }

    return 0; // если цифр нет, возвращаем 0 и success = 0
}


// static unsigned long long parse_unsigned_number(const char **str_ptr, int base, int *success) {
//     const char *p = *str_ptr;
//     unsigned long long result = 0;
//     *success = 0; // явно инициализируем успех

//     if (*p == '+') p++; // допустим знак +

//     int digits_read = 0;
//     while (*p) {
//         int digit = digit_value(*p);
//         if (digit < 0 || digit >= base) break;
//         result = result * base + digit;
//         p++;
//         digits_read++;
//     }

//     if (digits_read > 0) {
//         *success = 1;
//         *str_ptr = p;
//     }
//     return result;
// }

static unsigned long long parse_unsigned_number(const char **str_ptr, int base, int *success) {
    const char *p = *str_ptr;
    unsigned long long result = 0;
    *success = 0;

    if (*p == '+') p++; // допустимый знак +

    int digits_read = 0;
    while (*p) {
        int digit = digit_value(*p);
        if (digit < 0 || digit >= base) break;
        result = result * base + digit;
        p++;
        digits_read++;
    }

    if (digits_read > 0) {
        *success = 1;
        *str_ptr = p; // сдвигаем только если реально считали цифры
    }

    return result;
}



static int parse_char(const char **str_ptr, va_list args) {
  if (**str_ptr == '\0') return 0;
  
  char *c = va_arg(args, char *);
  if (c) {
    *c = **str_ptr;
    (*str_ptr)++;
    return 1;
  }
  return 0;
}

// static int parse_int_with_base(const char **str_ptr, int length_modifier, va_list args) {
//     // Пропускаем пробелы
//     while (isspace(**str_ptr)) (*str_ptr)++;
//     if (**str_ptr == '\0') return 0;

//     const char *p = *str_ptr;
//     int base = 10;
//     int sign = 1;

//     // Обработка знака
//     if (*p == '-') {
//         sign = -1;
//         p++;
//     } else if (*p == '+') {
//         p++;
//     }

//     // Определение базы
//     if (*p == '0') {
//         if (*(p + 1) == 'x' || *(p + 1) == 'X') {
//             base = 16;
//             p += 2; // пропускаем "0x"
//         } else {
//             base = 8;
//             p++; // пропускаем "0"
//         }
//     }

//     // Парсим число в нужной базе
//     int success = 0;
//     long long value = parse_number(&p, base, &success);
//     value *= sign;

//     if (!success) return 0;

//     // Сохраняем результат с учётом length_modifier
//     switch (length_modifier) {
//         case 'H': { signed char *ptr = va_arg(args, signed char *); if (ptr) *ptr = (signed char)value; break; }
//         case 'h': { short *ptr = va_arg(args, short *); if (ptr) *ptr = (short)value; break; }
//         case 'l': { long *ptr = va_arg(args, long *); if (ptr) *ptr = (long)value; break; }
//         case 'L': { long long *ptr = va_arg(args, long long *); if (ptr) *ptr = value; break; }
//         default: { int *ptr = va_arg(args, int *); if (ptr) *ptr = (int)value; break; }
//     }

//     *str_ptr = p; // Обновляем исходный указатель после числа
//     return 1;
// }

static int parse_int_with_base(const char **str_ptr, int length_modifier, va_list args) {
    while (isspace(**str_ptr)) (*str_ptr)++;
    if (**str_ptr == '\0') return 0;  // пустая строка → 0

    const char *start = *str_ptr;    // сохраняем начало
    const char *p = start;
    int base = 10;
    int sign = 1;

    if (*p == '-') { sign = -1; p++; }
    else if (*p == '+') { p++; }

    if (*p == '0') {
        if (*(p + 1) == 'x' || *(p + 1) == 'X') {
            base = 16; p += 2;
        } else base = 8, p++;
    }

    int success = 0;
    long long value = parse_number(&p, base, &success);
    value *= sign;

    if (!success) return 0;  // ничего не считано → 0

    switch (length_modifier) {
        case 'H': { signed char *ptr = va_arg(args, signed char *); if (ptr) *ptr = (signed char)value; break; }
        case 'h': { short *ptr = va_arg(args, short *); if (ptr) *ptr = (short)value; break; }
        case 'l': { long *ptr = va_arg(args, long *); if (ptr) *ptr = (long)value; break; }
        case 'L': { long long *ptr = va_arg(args, long long *); if (ptr) *ptr = value; break; }
        default: { int *ptr = va_arg(args, int *); if (ptr) *ptr = (int)value; break; }
    }

    *str_ptr = p;
    return 1;
}




static int parse_int(const char **str_ptr, int length_modifier, va_list args) {
  while (isspace(**str_ptr)) (*str_ptr)++;
  
  if (**str_ptr == '\0') return 0;
  
  int success = 0;
  long long value = parse_number(str_ptr, 10, &success);
  
  if (!success) return 0;
  
  switch (length_modifier) {
    case 'H': { signed char *p = va_arg(args, signed char *); if (p) *p = (signed char)value; break; }
    case 'h': { short *p = va_arg(args, short *); if (p) *p = (short)value; break; }
    case 'l': { long *p = va_arg(args, long *); if (p) *p = (long)value; break; }
    case 'L': { long long *p = va_arg(args, long long *); if (p) *p = value; break; }
    default: { int *p = va_arg(args, int *); if (p) *p = (int)value; break; }
  }
  
  return 1;
}

static int parse_string(const char **str_ptr, int width, va_list args) {
    while (isspace(**str_ptr)) (*str_ptr)++;

    char *str = va_arg(args, char *);
    if (!str) return 0; // проверяем на NULL

    int count = 0;
    while (**str_ptr && !isspace(**str_ptr) && (width == -1 || count < width)) {
        *str++ = **str_ptr;
        (*str_ptr)++;
        count++;
    }
    *str = '\0';
    return count > 0 ? 1 : 0;
}


static int parse_unsigned(const char **str_ptr, int length_modifier, va_list args) {
  while (isspace(**str_ptr)) (*str_ptr)++;
  
  if (**str_ptr == '\0') return 0;
  
  int success = 0;
  unsigned long long value = parse_unsigned_number(str_ptr, 10, &success);
  
  if (!success) return 0;
  
  switch (length_modifier) {
    case 'H': { unsigned char *p = va_arg(args, unsigned char *); if (p) *p = (unsigned char)value; break; }
    case 'h': { unsigned short *p = va_arg(args, unsigned short *); if (p) *p = (unsigned short)value; break; }
    case 'l': { unsigned long *p = va_arg(args, unsigned long *); if (p) *p = (unsigned long)value; break; }
    case 'L': { unsigned long long *p = va_arg(args, unsigned long long *); if (p) *p = value; break; }
    default: { unsigned int *p = va_arg(args, unsigned int *); if (p) *p = (unsigned int)value; break; }
  }
  
  return 1;
}

static int parse_octal(const char **str_ptr, int length_modifier, va_list args) {
  while (isspace(**str_ptr)) (*str_ptr)++;
  
  if (**str_ptr == '\0') return 0;
  
  int success = 0;
  unsigned long long value = parse_unsigned_number(str_ptr, 8, &success);
  
  if (!success) return 0;
  
  switch (length_modifier) {
    case 'H': { unsigned char *p = va_arg(args, unsigned char *); if (p) *p = (unsigned char)value; break; }
    case 'h': { unsigned short *p = va_arg(args, unsigned short *); if (p) *p = (unsigned short)value; break; }
    case 'l': { unsigned long *p = va_arg(args, unsigned long *); if (p) *p = (unsigned long)value; break; }
    case 'L': { unsigned long long *p = va_arg(args, unsigned long long *); if (p) *p = value; break; }
    default: { unsigned int *p = va_arg(args, unsigned int *); if (p) *p = (unsigned int)value; break; }
  }
  
  return 1;
}

// static int parse_hex(const char **str_ptr, int length_modifier, va_list args) {
//   while (isspace(**str_ptr)) (*str_ptr)++;
  
//   if (**str_ptr == '\0') return 0;
  
//   // Пропускаем опциональный префикс 0x/0X
//   const char *p = *str_ptr;
//   if (*p == '0' && (*(p+1) == 'x' || *(p+1) == 'X')) {
//     p += 2;
//     *str_ptr = p;
//   }
  
//   int success = 0;
//   unsigned long long value = parse_unsigned_number(str_ptr, 16, &success);
  
//   if (!success) return 0;
  
//   switch (length_modifier) {
//     case 'H': { unsigned char *ptr = va_arg(args, unsigned char *); if (ptr) *ptr = (unsigned char)value; break; }
//     case 'h': { unsigned short *ptr = va_arg(args, unsigned short *); if (ptr) *ptr = (unsigned short)value; break; }
//     case 'l': { unsigned long *ptr = va_arg(args, unsigned long *); if (ptr) *ptr = (unsigned long)value; break; }
//     case 'L': { unsigned long long *ptr = va_arg(args, unsigned long long *); if (ptr) *ptr = value; break; }
//     default: { unsigned int *ptr = va_arg(args, unsigned int *); if (ptr) *ptr = (unsigned int)value; break; }
//   }
  
//   return 1;
// }

static int parse_hex(const char **str_ptr, int length_modifier, va_list args) {
    while (isspace(**str_ptr)) (*str_ptr)++;
    if (**str_ptr == '\0') return 0;

    const char *start = *str_ptr;
    const char *p = start;

    if (*p == '0' && (*(p + 1) == 'x' || *(p + 1) == 'X')) p += 2;

    int success = 0;
    unsigned long long value = parse_unsigned_number(&p, 16, &success);
    if (!success) return 0;

    switch (length_modifier) {
        case 'H': { unsigned char *ptr = va_arg(args, unsigned char *); if (ptr) *ptr = (unsigned char)value; break; }
        case 'h': { unsigned short *ptr = va_arg(args, unsigned short *); if (ptr) *ptr = (unsigned short)value; break; }
        case 'l': { unsigned long *ptr = va_arg(args, unsigned long *); if (ptr) *ptr = (unsigned long)value; break; }
        case 'L': { unsigned long long *ptr = va_arg(args, unsigned long long *); if (ptr) *ptr = value; break; }
        default: { unsigned int *ptr = va_arg(args, unsigned int *); if (ptr) *ptr = (unsigned int)value; break; }
    }

    *str_ptr = p;
    return 1;
}



// static int parse_pointer(const char **str_ptr, va_list args) {
//     while (isspace(**str_ptr)) (*str_ptr)++;

//     if (**str_ptr == '\0') return 0;

//     const char *p = *str_ptr;
//     if (*p == '0' && (*(p + 1) == 'x' || *(p + 1) == 'X')) {
//         p += 2;
//         *str_ptr = p;
//     }

//     int success = 0;
//     unsigned long long value = parse_unsigned_number(str_ptr, 16, &success);
//     if (!success) return 0;

//     void **ptr = va_arg(args, void **);
//     if (ptr) *ptr = (void *)value;

//     return 1;
// }

// static int parse_pointer(const char **str_ptr, va_list args) {
//     while (isspace(**str_ptr)) (*str_ptr)++;
//     if (**str_ptr == '\0') return 0;

//     const char *p = *str_ptr;

//     // Префикс 0x/0X
//     if (*p == '0' && (*(p + 1) == 'x' || *(p + 1) == 'X')) {
//         p += 2;
//     }

//     int success = 0;
//     unsigned long long value = parse_unsigned_number(&p, 16, &success);

//     if (!success) return 0;

//     void **ptr = va_arg(args, void **);
//     if (ptr) *ptr = (void *)value;

//     *str_ptr = p; // обновляем указатель
//     return 1;
// }

static int parse_pointer(const char **str_ptr, va_list args) {
    while (isspace(**str_ptr)) (*str_ptr)++;
    if (**str_ptr == '\0') return 0;

    const char *start = *str_ptr;
    const char *p = start;

    if (*p == '0' && (*(p+1) == 'x' || *(p+1) == 'X')) p += 2;

    int success = 0;
    unsigned long long value = parse_unsigned_number(&p, 16, &success);
    if (!success) return 0;

    void **ptr = va_arg(args, void **);
    if (ptr) *ptr = (void *)value;

    *str_ptr = p;
    return 1;
}
