#include "monty.h"
global_var global_v;
/**
 * main - driver function for monty program
 * @argc: number of arguments
 * @argv: opcode file
 * Return: 0
 */
int main(int argc, char **argv)
{
	stack_t *stack;

	stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_file(argv[1], &stack);
	free_int(stack);
	return (0);
}
