#ifndef MONTY_H
#define MONTY_H
#include <stddef.h>
/**
 * enum data_format - Data Format (Stack or Queu)
 * @STACK_FORMAT: stack data format
 * @QUEUE_FORMAT: queue data format
 */
typedef enum data_format
{
	STACK_FORMAT = 1,
	QUEUE_FORMAT = 2
} data_format_t;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @arg: opcode arg (if required)
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	char *arg;
	int (*f)(stack_t **stack, unsigned int line_number, char *arg,
			data_format_t *format);
} instruction_t;

instruction_t *create_instruction_t(char *opcode, char *arg);
void free_instruction_t(instruction_t **inst);

void free_stack_t(stack_t **stack);
stack_t *push_stack_t(stack_t **stack, int value);
stack_t *pop_stack_t(stack_t **stack);
size_t count_stack_t(stack_t *stack);

stack_t *enqueue_stack_t(stack_t **queue, int value);
stack_t *dequeue_stack_t(stack_t **queue);

int push_opcode(stack_t **stack, unsigned int line_number, char *arg,
		data_format_t *format);
int pall_opcode(stack_t **stack, unsigned int line_number, char *arg,
		data_format_t *format);
int pint_opcode(stack_t **stack, unsigned int line_number, char *arg,
		data_format_t *format);
int pop_opcode(stack_t **stack, unsigned int line_number, char *arg,
		data_format_t *format);
int swap_opcode(stack_t **stack, unsigned int line_number, char *arg,
		data_format_t *format);
int add_opcode(stack_t **stack, unsigned int line_number, char *arg,
		data_format_t *format);
int nop_opcode(stack_t **stack, unsigned int line_number, char *arg,
		data_format_t *format);
int sub_opcode(stack_t **stack, unsigned int line_number, char *arg,
		data_format_t *format);
int div_opcode(stack_t **stack, unsigned int line_number, char *arg,
		data_format_t *format);
int interpret_file(const char *file);
#endif
