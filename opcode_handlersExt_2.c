#include "monty.h"
#include <stdio.h>

/**
 * mod_opcode - mod opcode handler
 * @stack: stack
 * @line_number: line number
 * @arg: argument
 * @format: stack / queue data format
 * Return: 1 on success 0 on failure
 */
int mod_opcode(stack_t **stack, unsigned int line_number,
		__attribute__((unused))char *arg, data_format_t *format)
{
	stack_t *op2 = NULL, *op1 = NULL, *result = NULL;

	if (count_stack_t(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
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
		result = push_stack_t(stack, op1->n % op2->n);
	else
		result = enqueue_stack_t(stack, op1->n % op2->n);
	free_stack_t(&op1);
	free_stack_t(&op2);
	return (result != NULL);
}
/**
 * pchar_opcode - pchar opcode handler
 * @stack: stack
 * @line_number: line number
 * @arg: argument
 * @format: data format (stack / queue).
 * Return: 1 on success 0 on failure
 */
int pchar_opcode(stack_t **stack, unsigned int line_number,
		__attribute__((unused))char *arg,
		__attribute__((unused))data_format_t *format)
{
	stack_t *tos = NULL;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		return (0);
	}
	tos = *stack;
	if (tos->n <= 0 || tos->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		return (0);
	}
	printf("%c\n", (char)tos->n);
	return (1);
}
/**
 * pst_opcode - pstr opcode handler
 * @stack: stack
 * @line_number: line number
 * @arg: argument
 * @format: format
 * Return: 1 always
 */
int pstr_opcode(stack_t **stack,
		__attribute__((unused))unsigned int line_number,
		__attribute__((unused))char *arg,
		__attribute__((unused))data_format_t *format)
{
	stack_t *current = (*stack);

	while (current != NULL && current->n > 0 && current->n <= 127)
	{
		printf("%c", (char)current->n);
		current = current->next;
	}
	printf("\n");
	return (1);
}
/**
 * rotl_opcode - rotl opcode handler
 * @stack: stack
 * @line_number: line number
 * @arg: argument
 * @format: format
 * Return: always 1
 */
int rotl_opcode(stack_t **stack,
		__attribute__((unused))unsigned int line_number,
		__attribute__((unused))char *arg,
		__attribute__((unused))data_format_t *format)
{
	stack_t *tos = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
		return (1);
	if (enqueue_stack_t(stack, (*stack)->n) != NULL)
	{
		tos = pop_stack_t(stack);
		free_stack_t(&tos);
		return (1);
	}
	else
		return (0);
}
/**
 * rotr_opcode - rotr opcode handler
 * @stack: stack
 * @line_number: line number
 * @arg: argument
 * @format: data format (stack or queue)
 * Return: 1 on success 0 on failure
 */
int rotr_opcode(stack_t **stack,
		__attribute__((unused))unsigned int line_number,
		__attribute__((unused))char *arg,
		__attribute__((unused))data_format_t *format)
{
	stack_t *last = NULL;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return (1);
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	if (last->prev != NULL)
		last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	return (1);
}
