#include "monty.h"

/**
 * _push - Push an integer onto the stack.
 * @stack: Linked list representing the monty stack
 * @line_number: Number of the line where the opcode occurs
 */
void _push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *top;
	(void)line_number;

	/* Allocate memory for a new stack element */
	top = malloc(sizeof(stack_t));
	if (!top)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Set the value of the new element */
	top->n = global_v.push_arg;
	top->next = *stack;
	top->prev = NULL;

	if (*stack)
		(*stack)->prev = top;
	*stack = top;
}

/**
 * _pall - Print all elements in the stack.
 * @stack: Pointer to the linked list stack
 * @line_number: Number of the line where the opcode occurs
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *runner;

	runner = *stack;
	while (runner)
	{
		printf("%d\n", runner->n);
		runner = runner->next;
	}
}

/**
 * _pint - Print the integer at the top of the stack.
 * @stack: Pointer to the linked list stack
 * @line_number: Number of the line where the opcode occurs
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;
	if (!runner)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", runner->n);
}

/**
 * _pop - Remove the top element from the stack.
 * @stack: Pointer to the linked list stack
 * @line_number: Number of the line where the opcode occurs
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *nodo = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	*stack = nodo->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(nodo);
}

/**
 * _swap - Swap the top two elements of the stack.
 * @stack: Pointer to the stack
 * @line_number: Line number where the opcode occurs
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;
	int tmp;

	runner = *stack;
	if (runner == NULL || runner->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	tmp = runner->n;
	runner->n = runner->next->n;
	runner->next->n = tmp;
}
