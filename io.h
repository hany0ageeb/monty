#ifndef IO_H
#define IO_H
#include <stddef.h>
#include <sys/types.h>
#include <stdio.h>
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
FILE *open_file(const char *file);
#endif
