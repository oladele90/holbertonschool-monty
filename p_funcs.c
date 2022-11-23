#include "monty.h"
int num;

/**
 *  - pushes new node to stack
 * : pointer to pointer of first node in stack
 * : current line number of file
 * Return: nothing
 */

void push_op(stack_t **first_node, unsigned int line_number)
{
	stack_t *new;
	(void) line_number;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
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
 * free_stack - frees a stack of nodes
 * @first_node: pointer to first node in stack
 * Return: nothing
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
 * pall_op - prints all numbers in stack
 * @first_node: pointer to pointer of first node in stack
 * @line_number: current line number of file
 * Return: nothing
 */

void pall_op(stack_t **first_node, unsigned int line_number)
{
	stack_t *my = *first_node;
	(void) line_number;
	while (my != NULL)
	{
		printf("%d\n", my->n);
		my = my->next;
	}
}

/**
 * pint_op - prints first number in stack
 * @first_node: pointer to pointer of first node in stack
 * @line_number: current line number of file
 */

void pint_op(stack_t **first_node, unsigned int line_number)
{
	if (*first_node == NULL && first_node == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*first_node)->n);
}
