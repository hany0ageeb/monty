#include "monty.h"
#include "string.h"
#include "io.h"
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
/**
 * is_alphanumeric - check if char is alpha numeric char
 * @c: char to check
 * Return: True if it is otherwise false
 */
int is_alphanumeric(const char c)
{
	return (
			(c >= 'a' && c <= 'z') ||
			(c >= 'A' && c <= 'Z') ||
			(c >= '0' && c <= '9')
			);
}
/**
 * is_at_end - check if c is end char in line
 * @c: char to check
 * Return: true if c is either '\0' or '\n' otherwise false.
 */
int is_at_end(const char c)
{
	return (c == '\0' || c == '\n');
}
/**
 * tokenize - given monty bytecode line return instruction_t object
 * @line: line of code
 * Return: instruction_t object
 */
instruction_t *tokenize(const char *line)
{
	size_t start = 0, current = 0;
	instruction_t *inst = NULL;

	errno = 0;
	while (line != NULL && !is_at_end(line[current]))
	{
		if (line[current] == ' ' || line[current] == '\t')
			while (!is_at_end(line[current]) &&
					(line[current] == ' ' || line[current] == '\t'))
				current++;
		else if (line[current] == '#')
			while (!is_at_end(line[current]))
				current++;
		else
		{
			if (inst == NULL)
				inst = create_instruction_t(NULL, NULL);
			if (inst == NULL)
				return (inst);
			while (!is_at_end(line[current]) && is_alphanumeric(line[current]))
				current++;
			if (inst->opcode == NULL)
				inst->opcode = sub_str(line, start, current - 1);
			else if (inst->arg == NULL)
			{
				inst->arg = sub_str(line, start, current - 1);
				if (errno != 0)
					free_instruction_t(&inst);
				return (inst);
			}
			if (errno != 0 && inst != NULL)
				free_instruction_t(&inst);
		}
		start = current;
	}
	return (inst);
}
/**
 * set_instruction_t_func - set handler function
 * @inst: instruction_t object
 * @line_number: line number
 * Return: 1 on success 0 on failure
 */
int set_instruction_t_func(instruction_t *inst, size_t line_number)
{
	if (inst != NULL)
	{
		inst->f = NULL;
		if (str_equal(inst->opcode, "push"))
			inst->f = &push_opcode;
		else if (str_equal(inst->opcode, "pall"))
			inst->f = &pall_opcode;
		else if (str_equal(inst->opcode, "pint"))
			inst->f = &pint_opcode;
		else if (str_equal(inst->opcode, "pop"))
			inst->f = &pop_opcode;
		else if (str_equal(inst->opcode, "swap"))
			inst->f = &swap_opcode;
		else if (str_equal(inst->opcode, "add"))
			inst->f = &add_opcode;
		else if (str_equal(inst->opcode, "nop"))
			inst->f = &nop_opcode;
		else if (str_equal(inst->opcode, "sub"))
			inst->f = &sub_opcode;
		else if (str_equal(inst->opcode, "div"))
			inst->f = &div_opcode;
		else
		{
			fprintf(stderr, "L%lu: unknown instruction %s\n",
					line_number, inst->opcode);
			return (0);
		}
	}
	return (1);
}
/**
 * interpret_file - interpret file
 * @file: file
 * Return: 0 on success -1 on error
 */
int interpret_file(const char *file)
{
	FILE *fptr = NULL;
	size_t line_number = 0, n = 0;
	ssize_t n_read = -1;
	char *lineptr = NULL;
	instruction_t *inst = NULL;
	data_format_t format = STACK_FORMAT;
	stack_t *stack = NULL;
	int ret = EXIT_SUCCESS;

	fptr = open_file(file);
	while ((n_read = _getline(&lineptr, &n, fptr)) != -1)
	{
		line_number++;
		inst = tokenize(lineptr);
		if (inst == NULL && errno != 0)
		{
			ret = EXIT_FAILURE;
			break;
		}
		if (set_instruction_t_func(inst, line_number))
		{
			if (!inst->f(&stack, line_number, inst->arg, &format))
			{
				ret = EXIT_FAILURE;
				break;
			}
		}
		else
		{
				ret = EXIT_FAILURE;
				break;
		}
		free_instruction_t(&inst);
	}
	if (lineptr != NULL)
		free(lineptr);
	fclose(fptr);
	free_stack_t(&stack);
	free_instruction_t(&inst);
	return (ret);
}
