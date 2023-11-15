#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * @argc: args count
 * @argv: arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	exit_code = interpret_file(argv[1]);
	exit(exit_code);
}
