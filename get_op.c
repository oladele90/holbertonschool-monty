#include "monty.h"

/**
 *
 *
 *
 */

void (*get_op(char *opcode, unsigned int line_number))(stack_t **, unsigned int)
{
	instruction_t ops [] = {
		{"push", push_op},
		{"pall", pall_op},
		{NULL, NULL}
	};
	int i;
	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
			return (ops[i].f);
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	return (NULL);
}
