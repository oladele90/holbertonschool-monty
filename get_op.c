#include "monty.h"

/**
 *
 *
 *
 */

void (*get_op(char *opcode))(stack_t **, unsigned int)
{
	instruction_t ops [] = {
		{"push", push_op},
		{NULL, NULL}
	};
	int i;
	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
			return (ops[i].f);
	}
	return (NULL);
}
