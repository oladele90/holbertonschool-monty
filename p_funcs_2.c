#include "monty.h"

/**
 * pop_op - deletes first node in stack
 * @first_node: pointer to pointer of first node in stack
 * @line_number: current line number in file
 */

void pop_op(stack_t **first_node, unsigned int line_number)
{
	stack_t *new;

	new = *first_node;
	if (new == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	new = new->next;
	free(*first_node);
	*first_node = new;
}
