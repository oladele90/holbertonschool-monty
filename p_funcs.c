#include "monty.h"
int num;

/**
 *
 *
 *
 */

void push_op(stack_t **first_node, unsigned int line_number)
{
	stack_t *new;
	(void) line_number;
	new = malloc(sizeof(stack_t));
	new->n = num;
	new->prev = NULL;
	if (first_node != NULL && *first_node != NULL)
	{
		new->next = *first_node;
		(*first_node)->prev = new;
	}
	else
		(new->next = NULL);
	*first_node = new;
}

/**
 *
 */

void free_stack(stack_t *first_node)
{
	stack_t *temp;

	if (first_node == NULL)
		return;
	while (first_node != NULL)
	{
		temp = first_node;
		first_node = first_node->next;
		free(temp);
	}
	free(first_node);
}

/**
 *
 */

void pall_op(stack_t **first_node, unsigned int line_number)
{
	(void) line_number;
	while (*first_node != NULL)
	{
		printf("%d\n", (*first_node)->n);
		*first_node = (*first_node)->next;
	}
}
