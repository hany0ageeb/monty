#include "monty.h"
#include <stdio.h>
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
	if (result == NULL)
		return (0);
	return (1);
}
