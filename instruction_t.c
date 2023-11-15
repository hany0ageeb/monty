#include "monty.h"
#include "mem.h"
#include <stdlib.h>

/**
 * create_instruction_t - create instruction_t object
 * @opcode: opcode
 * @arg: arg
 * Return: NULL if failed or pointer to allocated memory
 */
instruction_t *create_instruction_t(char *opcode, char *arg)
{
	instruction_t *inst = allocate_mem(sizeof(instruction_t));

	if (inst != NULL)
	{
		inst->opcode = opcode;
		inst->arg = arg;
	}
	return (inst);
}
/**
 * free_instruction_t - free instruction_t struct
 * @inst: instruction_t object to free
 */
void free_instruction_t(instruction_t **inst)
{
	if (inst != NULL && *inst != NULL)
	{
		if ((*inst)->opcode != NULL)
			free((*inst)->opcode);
		if ((*inst)->arg != NULL)
			free((*inst)->arg);
		free(*inst);
		*inst = NULL;
	}
}
