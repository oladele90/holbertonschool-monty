#include "monty.h"

/**
 * get_op - matches opcode to function
 * @opcode: token passed to function.
 * @line_number: current line number of file
 * Return: nothing
 */

void (*get_op(char *opcode, unsigned int line_number))(stack_t **, unsigned int
	)
{
	instruction_t ops[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pint", pint_op},
		{"pop", pop_op},
		{"swap", swap_op},
		{"add", add_op},
		{"nop", nop_op},
		{NULL, NULL}
	};
	int i;

	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
			return (ops[i].f);
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
	return (NULL);
}
