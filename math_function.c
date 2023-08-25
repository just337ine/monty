#include "monty.h"

/**
 * _addsub - Add or subtract the top two elements of the stack.
 * @stack: Pointer to the stack
 * @line_number: Line number where the opcode occurs
 */
void _addsub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int result = 0, n = 0;
	int is_sub = 0; /* Flag indicating whether to perform subtraction */

	/* Check if stack is empty */
	if (!tmp)
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n",
				line_number, is_sub ? "sub" : "add");
		exit(EXIT_FAILURE);
	}

	/* Count the number of elements in the stack */
	while (tmp)
	{
		tmp = tmp->next;
		n++;
	}

	/* Check if there are enough elements in the stack for operation */
	if (stack == NULL || (*stack)->next == NULL || n <= 1)
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n",
				line_number, is_sub ? "sub" : "add");
		exit(EXIT_FAILURE);
	}

	/* Perform addition or subtraction and update the stack */
	if (is_sub)
		result = (*stack)->next->n - (*stack)->n;
	else
		result = (*stack)->next->n + (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = result;
}

/**
 * _divmod - Perform division or modulus operation on the stack's top elements
 * @stack: pointer to the stack
 * @line_number: line number where the opcode occurs
 */
void _divmod(stack_t **stack, unsigned int line_number)
{
	int divisor = 0;
	int is_mod = 0; /*Flag to indicate whether it's a modulus operation */

	/* Check if there are enough elements in the stack for operation */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't perform operation, stack too short\n",
				line_number);
		free(global_v.buffer);
		fclose(global_v.file);
		free_int(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		/* Check for division by zero */
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(global_v.buffer);
		fclose(global_v.file);
		free_int(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		divisor = (*stack)->n;
		_pop(stack, line_number);
		if (is_mod)
			(*stack)->n %= divisor;
		else
			(*stack)->n /= divisor;
	}
}


/**
 * _mul - Multiply top element with second top element of the stack.
 * @stack: pointer to the stack
 * @line_number: line number where the opcode occurs
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int a;

	/* Check if there are enough elements in the stack for multiplication */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(global_v.buffer);
		fclose(global_v.file);
		free_int(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Perform multiplication and update the stack */
		a = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n *= a;
	}
}
