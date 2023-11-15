#ifndef STRING_H
#define STRING_H
#include <stddef.h>
char *sub_str(const char *str, size_t start, size_t end);
int is_null_or_empty(const char *str);
int str_equal(const char *str1, const char *str2);
int is_integer(const char *str);
#endif
