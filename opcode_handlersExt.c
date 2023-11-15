#include "monty.h"
#include <stdio.h>

/**
 * nop_opcode - nop opcode handler
 * @stack: stack
 * @line_number: line number
 * @arg: argument
 * @format: stack / queue data format
 * Return: 1 always
 */
int nop_opcode(
		__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int line_number,
		__attribute__((unused)) char *arg,
		__attribute__((unused)) data_format_t *format)
{
	return (1);
}
/**
 * add_opcode - handle add opcode
 * @stack: stack
 * @line_number: line number
 * @arg: argument
 * @format: data format
 * Return: 1 on success 0 on failure
 */
int add_opcode(stack_t **stack, unsigned int line_number,
		__attribute__((unused))char *arg, data_format_t *format)
{
	stack_t *op2, *op1, *result;

	if (count_stack_t(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		return (0);
	}
	op2 = pop_stack_t(stack);
	op1 = pop_stack_t(stack);
	if ((*format) == STACK_FORMAT)
		result = push_stack_t(stack, op1->n + op2->n);
	else
		result = enqueue_stack_t(stack, op1->n + op2->n);
	free_stack_t(&op1);
	free_stack_t(&op2);
	return (result != NULL);
}
/**
 * sub_opcode - handle sub opcode
 * @stack: stack
 * @line_number: line number
 * @arg: argument
 * @format: stack or queue data format
 * Return: 1 on success otherwise 0
 */
int sub_opcode(stack_t **stack, unsigned int line_number,
		__attribute__((unused))char *arg, data_format_t *format)
{
	stack_t *op2, *op1, *result;

	if (count_stack_t(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		return (0);
	}
	op2 = pop_stack_t(stack);
	op1 = pop_stack_t(stack);
	if ((*format) == STACK_FORMAT)
		result = push_stack_t(stack, op1->n - op2->n);
	else
		result = enqueue_stack_t(stack, op1->n - op2->n);
	free_stack_t(&op1);
	free_stack_t(&op2);
	return (result != NULL);
}
/**
 * div_opcode - div opcode handler
 * @stack: stack
 * @line_number: line number
 * @arg: argument
 * @format: stack or queue data format
 * Return: 1 on success 0 on failure
 */
int div_opcode(stack_t **stack, unsigned int line_number,
		__attribute__((unused))char *arg, data_format_t *format)
{
	stack_t *op2 = NULL, *op1 = NULL, *result = NULL;

	if (count_stack_t(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		return (0);
	}
	op2 = pop_stack_t(stack);
	if (op2->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack_t(&op2);
		return (0);
	}
	op1 = pop_stack_t(stack);
	if ((*format) == STACK_FORMAT)
		result = push_stack_t(stack, op1->n / op2->n);
	else
		result = enqueue_stack_t(stack, op1->n / op2->n);
	free_stack_t(&op1);
	free_stack_t(&op2);
	return (result != NULL);
}
