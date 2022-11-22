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

/**
 * swap_op - swaps elements in first two nodes of stack
 * @first_node: pointer to pointer of first node in stack
 * @line_number: current line number in file
 */

void swap_op(stack_t **first_node, unsigned int line_number)
{
	int i;

	if (*first_node == NULL || (*first_node)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	i = (*first_node)->n;
	(*first_node)->n = (*first_node)->next->n;
	(*first_node)->next->n = i;
}
