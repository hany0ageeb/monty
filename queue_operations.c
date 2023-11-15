#include "monty.h"
#include "mem.h"
#include <stdlib.h>

/**
 * enqueue_stack_t - enqueue value in end of queue
 * @value: value
 * @queue: queue
 * Return: pointer to new node or NULL
 */
stack_t *enqueue_stack_t(stack_t **queue, int value)
{
	stack_t *node = allocate_mem(sizeof(stack_t));
	stack_t *tail = *queue;

	if (node != NULL)
	{
		node->n = value;
		node->next = NULL;
		if (*queue == NULL)
		{
			node->prev = NULL;
			*queue = node;
		}
		else
		{
			while (tail->next != NULL)
				tail = tail->next;
			node->prev = tail;
			tail->next = node;
		}
	}
	return (node);
}
/**
 * dequeue_stack_t - dequeue stack from front
 * @queue: queue
 * Return: NULL if empty otherwise the front of the queue
 */
stack_t *dequeue_stack_t(stack_t **queue)
{
	stack_t *tmp;

	if (*queue == NULL)
		return (NULL);
	tmp = *queue;
	*queue = (*queue)->next;
	tmp->next = NULL;
	return (tmp);
}
