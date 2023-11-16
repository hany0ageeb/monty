#include "string.h"
#include "mem.h"
#include <errno.h>
/**
 * sub_str - sub string
 * @str: string
 * @start: start index >= 0 inclusive
 * @end: end index >= 0 execlusive
 * Return: NULL if failed or pointer to a newly created substring
 */
char *sub_str(const char *str, size_t start, size_t end)
{
	size_t len, i;
	char *tmp = NULL;

	errno = 0;
	if (str == NULL)
		return (NULL);
	if (start > end)
		return (NULL);
	len = end - start + 1;
	tmp = (char *)allocate_mem(len + 1);
	if (tmp != NULL)
	{
		for (i = 0; start <= end && i < len; start++, i++)
			tmp[i] = str[start];
		tmp[i] = '\0';
	}
	return (tmp);
}
/**
 * is_null_or_empty - check if str is NULL or Empty string
 * @str: string
 * Return: true if empty or null otherwise false
 */
int is_null_or_empty(const char *str)
{
	return (str == NULL || *str == '\0');
}
/**
 * str_equal - check if two strings are equal
 * @str1: first string
 * @str2: second string
 * Return: 1 if equals otherwsie 0
 */
int str_equal(const char *str1, const char *str2)
{
	size_t i;

	if (str1 == str2)
		return (1);
	if (str1 == NULL || str2 == NULL)
		return (0);
	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; ++i)
	{
		if (str1[i] != str2[i])
			return (0);
	}
	if (str1[i] == '\0' && str2[i] == '\0')
		return (1);
	return (0);
}
/**
 * is_integer - check if str is a calid integer [+-]*[0-9]
 * @str: string to check
 * Return: 1 if is valid integer otherwise 0
 */
int is_integer(const char *str)
{
	size_t i = 0;

	if (is_null_or_empty(str))
		return (0);
	if (str[0] == '-')
		i = 1;
	for (; str[i] != '\0'; ++i)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
