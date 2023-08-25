#include "monty.h"

/**
 * nothing - No operation, do nothing.
 * @stack: Pointer to the stack
 * @line_number: Line number where the opcode occurs
 */
void nothing(stack_t **stack, unsigned int line_number)
{
	/* No operation, function does nothing */
	(void)stack;
	(void)line_number;
}

/**
 * _pchar - Print the ASCII value of the top element of the stack.
 * @stack: Pointer to the stack
 * @line_number: Line number where the opcode occurs
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int val;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(global_v.buffer);
		fclose(global_v.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	val = (*stack)->n;
	if (val > 127 || val < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(global_v.buffer);
		fclose(global_v.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	putchar(val);
	putchar('\n');
}

/**
 * _pstr - Print the ASCII characters represented by values on the stack.
 * @stack: Pointer to the stack
 * @line_number: Line number where the opcode occurs
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int c = 0;
	(void)line_number;

	/* Iterate through the stack and print the corresponding ASCII characters */
	while (tmp)
	{
		c = tmp->n;
		char num_str[12];

		sprintf(num_str, "%d", c);
		if (!is_integer(num_str))
			break;
		if (c < 0 || c > 127)
			break;
		putchar(c);
		tmp = tmp->next;
	}
	putchar('\n');
}
/**
 * read_file - reads a bytecode file and runs commands
 * @filename: pathname to file
 * @stack: pointer to the top of the stack
 */
void read_file(char *filename, stack_t **stack)
{
	char *line;
	size_t i = 0;
	int line_count = 1, check, read;
	instruct_func s;

	global_v.file = fopen(filename, "r");

	if (!global_v.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&global_v.buffer, &i, global_v.file)) != -1)
	{
		line = parse_line(global_v.buffer, stack, line_count);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		s = get_opcode(line);
		if (!s)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
			exit(EXIT_FAILURE);
		}
		s(stack, line_count);
		line_count++;
	}
	free(global_v.buffer);
	check = fclose(global_v.file);
	if (check == -1)
		exit(-1);
}
