/**
 *
 *
 *
 */

void push_op(stack_t **first_node, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (first_node != NULL)
	{
		new->next = first_node;
		first_node->prev = new;
	}
	new->prev = NULL;
	new->n = num;
	first_node = new;
}
