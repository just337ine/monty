#include "monty.h"

/**
 * free_int - Free the entire linked list.
 * @head: Pointer to the first node of the linked list
 */
void free_int(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
