#include "monty.h"
#include "mem.h"
#include <stdlib.h>

/**
 * push_stack_t - push value into stack
 * @stack: stack
 * @value: new value
 * Return: newly created node pointer or NULL if failed
 */
stack_t *push_stack_t(stack_t **stack, int value)
{
	stack_t *node = (stack_t *)allocate_mem(sizeof(stack_t));

	if (node != NULL)
	{
		node->n = value;
		node->prev = NULL;
		node->next = *stack;
		if (*stack != NULL)
			(*stack)->prev = node;
		*stack = node;
	}
	return (node);
}
/**
 * pop_stack_t - pop top of stack
 * @stack: stack
 * Return: Null if empty otherwise TOS
 */
stack_t *pop_stack_t(stack_t **stack)
{
	stack_t *tmp = NULL;

	if (*stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = NULL;
		tmp->prev = NULL;
		if (*stack != NULL)
			(*stack)->prev = NULL;
	}
	return (tmp);
}
/**
 * count_stack_t - count num of elem in stack
 * @tos: top of stack node pointer
 * Return: count of elements in the stack or 0 if empty
 */
size_t count_stack_t(stack_t *tos)
{
	size_t count = 0;

	while (tos != NULL)
	{
		count++;
		tos = tos->next;
	}
	return (count);
}
/**
 * free_stack_t - free memory allocated to stack_t
 * @stack: stack_t object pointer
 */
void free_stack_t(stack_t **stack)
{
	stack_t *tmp = NULL;

	if (stack != NULL && *stack != NULL)
	{
		while ((*stack) != NULL)
		{
			(*stack)->prev = NULL;
			tmp = *stack;
			(*stack) = (*stack)->next;
			free(tmp);
		}
	}
}
