#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  s21_size_t success = n;
  const unsigned char *ptr_str = (const unsigned char *)str;
  if (str != S21_NULL) {
    s21_size_t i = 0;
    while (i < n && success == n) {
      if (ptr_str[i] == (unsigned char)c) {
        success = i;
        break;
      }
      i++;
    }
  }
  return success == n ? S21_NULL : (void *)(ptr_str + success);
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int ret = 0;
  if (str1 != S21_NULL && str2 != S21_NULL) {
    const unsigned char *ptr_str1 = (const unsigned char *)str1;
    const unsigned char *ptr_str2 = (const unsigned char *)str2;
    for (s21_size_t i = 0; i < n && ret == 0; i++) {
      if (ptr_str1[i] != ptr_str2[i]) {
        ret = (int)ptr_str1[i] - (int)ptr_str2[i];
      }
    }
  } else if (str1 != str2) {
    if (str1 == S21_NULL) {
      ret = -1;
    } else {
      ret = 1;
    }
  }
  return ret;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  if (dest != NULL && src != NULL) {
    unsigned char *ptr_dest = (unsigned char *)dest;
    const unsigned char *ptr_src = (const unsigned char *)src;
    for (s21_size_t i = 0; i < n; i++) {
      ptr_dest[i] = ptr_src[i];
    }
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  if (str != S21_NULL) {
    unsigned char *ptr_str = (unsigned char *)str;
    for (s21_size_t i = 0; i < n; i++) {
      ptr_str[i] = (unsigned char)c;
    }
  }
  return str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  if (dest != S21_NULL && src != S21_NULL) {
    s21_size_t size_dest = s21_strlen(dest);
    s21_size_t count = 0;
    while (count < n && src[count] != '\0') {
      dest[size_dest + count] = src[count];
      count++;
    }
    dest[size_dest + count] = '\0';
  }
  return dest;
}

char *s21_strchr(const char *str, int c) {
  return (char *)s21_memchr((const void *)str, c, s21_strlen(str) + 1);
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t size = s21_strlen(str1) + 1;
  size = size > s21_strlen(str2) + 1 ? s21_strlen(str2) + 1 : size;
  size = size > n ? n : size;
  return s21_memcmp((const void *)str1, (const void *)str2, size);
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  if (dest == S21_NULL || src == S21_NULL) return S21_NULL;

  char *orig_dest = dest;

  while (n > 0 && *src != '\0') {
    *dest++ = *src++;
    n--;
  }

  while (n > 0) {
    *dest++ = '\0';
    n--;
  }

  return orig_dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i = 0;

  while (str1[i] != '\0' && !s21_strchr(str2, str1[i])) i++;

  return i;
}

char *s21_strerror(int errnum) {
  char *error = "";
#ifdef __linux__
  static char *linux_errors[] = {
      "Success",
      "Operation not permitted",
      "No such file or directory",
      "No such process",
      "Interrupted system call",
      "Input/output error",
      "No such device or address",
      "Argument list too long",
      "Exec format error",
      "Bad file descriptor",
      "No child processes",
      "Resource temporarily unavailable",
      "Cannot allocate memory",
      "Permission denied",
      "Bad address",
      "Block device required",
      "Device or resource busy",
      "File exists",
      "Invalid cross-device link",
      "No such device",
      "Not a directory",
      "Is a directory",
      "Invalid argument",
      "Too many open files in system",
      "Too many open files",
      "Inappropriate ioctl for device",
      "Text file busy",
      "File too large",
      "No space left on device",
      "Illegal seek",
      "Read-only file system",
      "Too many links",
      "Broken pipe",
      "Numerical argument out of domain",
      "Numerical result out of range",
      "Resource deadlock avoided",
      "File name too long",
      "No locks available",
      "Function not implemented",
      "Directory not empty",
      "Too many levels of symbolic links",
      "Unknown error 41",
      "No message of desired type",
      "Identifier removed",
      "Channel number out of range",
      "Level 2 not synchronized",
      "Level 3 halted",
      "Level 3 reset",
      "Link number out of range",
      "Protocol driver not attached",
      "No CSI structure available",
      "Level 2 halted",
      "Invalid exchange",
      "Invalid request descriptor",
      "Exchange full",
      "No anode",
      "Invalid request code",
      "Invalid slot",
      "Unknown error 58",
      "Bad font file format",
      "Device not a stream",
      "No data available",
      "Timer expired",
      "Out of streams resources",
      "Machine is not on the network",
      "Package not installed",
      "Object is remote",
      "Link has been severed",
      "Advertise error",
      "Srmount error",
      "Communication error on send",
      "Protocol error",
      "Multihop attempted",
      "RFS specific error",
      "Bad message",
      "Value too large for defined data type",
      "Name not unique on network",
      "File descriptor in bad state",
      "Remote address changed",
      "Can not access a needed shared library",
      "Accessing a corrupted shared library",
      ".lib section in a.out corrupted",
      "Attempting to link in too many shared libraries",
      "Cannot exec a shared library directly",
      "Invalid or incomplete multibyte or wide character",
      "Interrupted system call should be restarted",
      "Streams pipe error",
      "Too many users",
      "Socket operation on non-socket",
      "Destination address required",
      "Message too long",
      "Protocol wrong type for socket",
      "Protocol not available",
      "Protocol not supported",
      "Socket type not supported",
      "Operation not supported",
      "Protocol family not supported",
      "Address family not supported by protocol",
      "Address already in use",
      "Cannot assign requested address",
      "Network is down",
      "Network is unreachable",
      "Network dropped connection on reset",
      "Software caused connection abort",
      "Connection reset by peer",
      "No buffer space available",
      "Transport endpoint is already connected",
      "Transport endpoint is not connected",
      "Cannot send after transport endpoint shutdown",
      "Too many references: cannot splice",
      "Connection timed out",
      "Connection refused",
      "Host is down",
      "No route to host",
      "Operation already in progress",
      "Operation now in progress",
      "Stale file handle",
      "Structure needs cleaning",
      "Not a XENIX named type file",
      "No XENIX semaphores available",
      "Is a named type file",
      "Remote I/O error",
      "Disk quota exceeded",
      "No medium found",
      "Wrong medium type",
      "Operation canceled",
      "Required key not available",
      "Key has expired",
      "Key has been revoked",
      "Key was rejected by service",
      "Owner died",
      "State not recoverable",
      "Operation not possible due to RF-kill",
      "Memory page has hardware error",
      "Unknown error"};
#elif __APPLE__
  static char *macos_errors[] = {
      "Error 0",
      "Operation not permitted",
      "No such file or directory",
      "No such process",
      "Interrupted function call",
      "Input/output error",
      "No such device or address",
      "Arg list too long",
      "Exec format error",
      "Bad file descriptor",
      "No child processes",
      "Resource deadlock avoided",
      "Cannot allocate memory",
      "Permission denied",
      "Bad address",
      "Not a block device",
      "Resource busy",
      "File exists",
      "Improper link",
      "Operation not supported by device",
      "Not a directory",
      "Is a directory",
      "Invalid argument",
      "Too many open files in system",
      "Too many open files",
      "Inappropriate ioctl for device",
      "Text file busy",
      "File too large",
      "Device out of space",
      "Illegal seek",
      "Read-only file system",
      "Too many links",
      "Broken pipe",
      "Numerical argument out of domain",
      "Numerical result out of range",
      "Resource temporarily unavailable",
      "Operation now in progress",
      "Operation already in progress",
      "Socket operation on non-socket",
      "Destination address required",
      "Message too long",
      "Protocol wrong type for socket",
      "Protocol not available",
      "Protocol not supported",
      "Socket type not supported",
      "Not supported",
      "Protocol family not supported",
      "Address family not supported by protocol family",
      "Address already in use",
      "Cannot assign requested address",
      "Network is down",
      "Network is unreachable",
      "Network dropped connection on reset",
      "Software caused connection abort",
      "Connection reset by peer",
      "No buffer space available",
      "Socket is already connected",
      "Socket is not connected",
      "Cannot send after socket shutdown",
      "Operation timed out",
      "Connection refused",
      "Too many levels of symbolic links",
      "File name too long",
      "Host is down",
      "No route to host",
      "Directory not empty",
      "Too many processes",
      "Too many users",
      "Disc quota exceeded",
      "Stale NFS file handle",
      "Bad RPC struct",
      "RPC version wrong",
      "RPC prog. not avail.",
      "Program version wrong",
      "Bad procedure for program",
      "No locks available",
      "Function not implemented",
      "Inappropriate file type or format",
      "Authentication error",
      "Need authenticator",
      "Device power is off",
      "Device error",
      "Value too large to be stored in data type",
      "Bad executable (or shared library)",
      "Bad CPU type in executable",
      "Shared library version mismatch",
      "Malformed Mach-o file",
      "Operation canceled",
      "Identifier removed",
      "No message of desired type",
      "Illegal byte sequence",
      "No attribute found",
      "Bad message",
      "Reserved",
      "No message available",
      "Reserved",
      "No STREAM resources",
      "Not a STREAM",
      "Protocol error",
      "STREAM ioctl() timeout",
      "Operation	not supported on socket",
      "Unknown error"};
#endif

  if (errnum >= 0) {
#ifdef __linux__
    if (errnum < (int)(sizeof(linux_errors) / sizeof(linux_errors[0])) - 1) {
      error = linux_errors[errnum];
    }
#elif __APPLE__
    if (errnum < (int)(sizeof(macos_errors) / sizeof(macos_errors[0])) - 1) {
      error = macos_errors[errnum];
    }
#endif
  } else {
#ifdef __linux__
    error = linux_errors[sizeof(linux_errors) / sizeof(linux_errors[0]) - 1];
#elif __APPLE__
    error = macos_errors[sizeof(macos_errors) / sizeof(macos_errors[0]) - 1];
#endif
  }
  return error;
}

s21_size_t s21_strlen(const char *src) {
  s21_size_t i = 0;
  if (src != NULL) {
    while (src[i] != '\0') i++;
  }
  return i;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  if (str1 == S21_NULL || str2 == S21_NULL) return S21_NULL;

  char *result = S21_NULL;

  for (s21_size_t i = 0; result == S21_NULL && str1[i] != '\0'; i++) {
    for (s21_size_t j = 0; result == S21_NULL && str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) result = (char *)&str1[i];
    }
  }

  return result;
}

char *s21_strrchr(const char *str, int c) {
  if (str == S21_NULL) return S21_NULL;
  char *result = S21_NULL;

  for (int i = s21_strlen(str); result == S21_NULL && i >= 0; i--)
    if (str[i] == c) result = (char *)&str[i];

  return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
  if (haystack == S21_NULL || needle == S21_NULL) return S21_NULL;

  char *result = S21_NULL;

  for (s21_size_t i = 0; result == S21_NULL && haystack[i] != '\0'; i++) {
    s21_size_t j = 0;
    while (haystack[i + j] == needle[j] && needle[j] != '\0') j++;

    if (needle[j] == '\0') result = (char *)&haystack[i];
  }

  return result;
}

char *s21_strtok(char *str, const char *delim) {
  if (delim == S21_NULL) return S21_NULL;

  static char *next_token = S21_NULL;
  char *token = S21_NULL;

  if (str) next_token = str;

  if (next_token) {
    while (*next_token && s21_strchr(delim, *next_token)) next_token++;

    if (*next_token != '\0') {
      token = next_token;

      while (*next_token && !s21_strchr(delim, *next_token)) next_token++;

      if (*next_token)
        *next_token++ = '\0';
      else
        next_token = S21_NULL;
    }
  }

  return token;
}

char *s21_strcpy(char *dest, const char *src) {
  if (dest == S21_NULL || src == S21_NULL) return S21_NULL;

  char *ptr = dest;
  while ((*ptr++ = *src++) != '\0') {
  }

  return dest;
}

void *s21_to_upper(const char *str) {
  if (str == S21_NULL) return S21_NULL;

  s21_size_t len = s21_strlen(str);
  char *result = (char *)malloc((len + 1) * sizeof(char));

  if (result != S21_NULL) {
    for (s21_size_t i = 0; i < len; i++) {
      if (str[i] >= 'a' && str[i] <= 'z')
        result[i] = str[i] - 32;
      else
        result[i] = str[i];
    }
    result[len] = '\0';
  }

  return result;
}

void *s21_to_lower(const char *str) {
  if (str == S21_NULL) return S21_NULL;

  s21_size_t len = s21_strlen(str);
  char *result = (char *)malloc((len + 1) * sizeof(char));

  if (result != S21_NULL) {
    for (s21_size_t i = 0; i < len; i++) {
      if (str[i] >= 'A' && str[i] <= 'Z')
        result[i] = str[i] + 32;
      else
        result[i] = str[i];
    }
    result[len] = '\0';
  }

  return result;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == S21_NULL || str == S21_NULL) return S21_NULL;

  char *result = S21_NULL;
  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);

  if (start_index <= src_len) {
    result = (char *)malloc((src_len + str_len + 1) * sizeof(char));
    if (result != S21_NULL) {
      s21_strncpy(result, src, start_index);
      s21_strcpy(result + start_index, str);
      s21_strcpy(result + start_index + str_len, src + start_index);
    }
  }

  return result;
}

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == S21_NULL) return S21_NULL;

  const char *start = src;
  while (*start != '\0' && s21_strchr(trim_chars, *start) != S21_NULL) start++;

  const char *end = start + s21_strlen(start) - 1;
  while (end >= start && s21_strchr(trim_chars, *end) != S21_NULL) end--;

  s21_size_t len = (s21_size_t)(end - start) + 1;
  char *result = (char *)malloc((len + 1) * sizeof(char));
  if (result != S21_NULL) {
    s21_strncpy(result, start, len);
    result[len] = '\0';
  }

  return result;
}
