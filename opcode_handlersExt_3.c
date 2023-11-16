#include "monty.h"
#include <stdio.h>

/**
 * stack_opcode - mod opcode handler
 * @stack: stack
 * @line_number: line number
 * @arg: argument
 * @format: stack / queue data format
 * Return: 1 on success 0 on failure
 */
int stack_opcode(
		__attribute__((unused))stack_t **stack,
		__attribute__((unused))unsigned int line_number,
		__attribute__((unused))char *arg,
		data_format_t *format)
{
	*format = STACK_FORMAT;
	return (1);
}
/**
 * queue_opcode - queue opcode handelr
 * @stack: stack
 * @line_number: line number
 * @arg: argument
 * @format: data format STACK / QUEUE
 * Return: always 1
 */
int queue_opcode(
		__attribute__((unused))stack_t **stack,
		__attribute__((unused))unsigned int line_number,
		__attribute__((unused))char *arg,
		data_format_t *format)
{
	*format = QUEUE_FORMAT;
	return (1);
}
