#include "monty.h"

/**
 * _rotl - Rotate the stack to the left.
 * @stack: Pointer to the stack
 * @line_number: Line number where the opcode occurs
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;
	int aux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	/* Save the value of the top element */
	aux1 = runner->n;

	/*Move each element to the left, starting from the second element */
	while (runner->next)
	{
		runner = runner->next;
		runner->prev->n = runner->n;
	}

	/* Set the value of the last element to the saved top value */
	runner->n = aux1;
}

/**
 * _rotr - Rotate the stack to the right.
 * @stack: Pointer to the stack
 * @line_number: Line number where the opcode occurs
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;
	int aux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	/* Find the last element */
	while (runner->next)
		runner = runner->next;

	/* Save the value of the last element */
	aux1 = runner->n;

	/* Move each element to the right, starting from the last element */
	while (runner->prev)
	{
		runner = runner->prev;
		runner->next->n = runner->n;
	}

	/* Set the value of the first element to the saved last value */
	runner->n = aux1;
}
