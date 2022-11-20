#include "monty.h"

/**
 *
 *
 *
 */

void (*get_op(char *opcode))
{
	instruction_t ops [] = {
		{"push", push_op},
		{"pall", pall_op},
		{NULL, NULL}
	};
	int i;
	for (i = 0; ops[i]->opcode != NULL; i++)
	{
		if (strcmp(command, ops[i].opcode) == 0)
			return (ops[i].f);
	}
	return (NULL);
}
