#include "io.h"
#include "mem.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
/**
 * _getline - getline
 * @lineptr: line pointer
 * @n: ptr size
 * @stream: file stream to read from
 * Return: -1 or number or read chars
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	const size_t INITALLOC = 16, ALLOCSTEP = 16;
	size_t num_read = 0, new_size = 0;
	char *tmp = NULL;
	int c = -1;

	if ((lineptr == NULL) || (n == NULL))
	{
		errno = EINVAL;
		return (-1);
	}
	if (*lineptr == NULL)
	{
		*lineptr = allocate_mem(INITALLOC);
		if (*lineptr == NULL)
			return (-1);
		*n = INITALLOC;
	}
	while ((c = fgetc(stream)) != -1 && c != '\n')
	{
		num_read++;
		if (num_read >= *n)
		{
			new_size = *n + ALLOCSTEP;
			tmp = _realloc(*lineptr, *n + 1, new_size + 1);
			if (tmp == NULL)
				return (-1);
			*lineptr = tmp;
			*n = new_size;
		}
		(*lineptr)[num_read - 1] = (char)c;
	}
	if (c == '\n')
		(*lineptr)[num_read++] = '\n';
	(*lineptr)[num_read] = '\0';
	if (c == -1)
	{
		errno = 0;
		return (-1);
	}
	return ((ssize_t)num_read);
}
/**
 * open_file - open file for reading
 * @file: file to read
 * Return: NULL if cannot open file
 */
FILE *open_file(const char *file)
{
	FILE *fptr = NULL;

	fptr = fopen(file, "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	return (fptr);
}
