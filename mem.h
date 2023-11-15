#ifndef MEM_H
#define MEM_H
#include <stddef.h>
void *_realloc(void *ptr, size_t old_size, size_t new_size);
void *allocate_mem(size_t size);
#endif
