#include "monty.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/**
 * push_opcode - push opcode handler
 * @stack: stack
 * @line_number: line number
 * @arg: argument
 * @format: data format - stack or queue
 * Return: 1 on success 0 on failure
 */
int push_opcode(stack_t **stack, unsigned int line_number,
		char *arg, data_format_t *format)
{
	stack_t *node = NULL;

	if (!is_integer(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		return (0);
	}
	if ((*format) == STACK_FORMAT)
		node = push_stack_t(stack, atoi(arg));
	else
		node = enqueue_stack_t(stack, atoi(arg));
	if (node == NULL)
		return (0);
	return (1);
}
/**
 * pall_opcode - pall opcode handler
 * @stack: stack
 * @line_number: line number
 * @arg: argument
 * @format: data format
 * Return: 1 on success 0 on failure
 */
int pall_opcode(stack_t **stack,
		__attribute__((unused))unsigned int line_number,
		__attribute__((unused))char *arg,
		__attribute__((unused))data_format_t *format)
{
	stack_t *tos = *stack;

	while (tos != NULL)
	{
		printf("%d\n", tos->n);
		tos = tos->next;
	}
	return (1);
}
/**
 * pint_opcode - pint opcode handler
 * @stack: stack
 * @line_number: line number
 * @arg: argument
 * @format: stack or queue data fiormat
 * Return: 1 on success 0 on failure
 */
int pint_opcode(stack_t **stack, unsigned int line_number,
		__attribute__((unused))char *arg,
		__attribute__((unused))data_format_t *format)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n",
				line_number);
		return (0);
	}
	printf("%d\n", (*stack)->n);
	return (1);
}
/**
 * pop_opcode - pop opcode handler
 * @stack: stack
 * @line_number: line number
 * @arg: argument
 * @format: stack or queue data format
 * Return: 1 on success 0 on failure
 */
int pop_opcode(stack_t **stack, unsigned int line_number,
		__attribute__((unused))char *arg,
		__attribute__((unused))data_format_t *format)
{
	stack_t *tmp = NULL;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n",
				line_number);
		return (0);
	}
	tmp = pop_stack_t(stack);
	free_stack_t(&tmp);
	return (1);
}
/**
 * swap_opcode - swap opcode handler
 * @stack: stack
 * @line_number: line number
 * @arg: argument
 * @format: stack or queue data format
 * Return: 1 on sucess 0 on failure
 */
int swap_opcode(stack_t **stack, unsigned int line_number,
		__attribute__((unused))char *arg,
		__attribute((unused))data_format_t *format)
{
	int tmp;

	if (count_stack_t(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
				line_number);
		return (0);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
	return (1);
}
