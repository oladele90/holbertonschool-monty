#include "monty.h"

void open(char **argv)
{
	void (*p_func)(stack_t **, unsigned int);
	int num;
	char* buf = NULL, *token = NULL, command[1024];
	size_t len = 0;
	ssize_t line_size;
	unsigned int line_number = 1;
	stack_t *first_node;
	FILE *file = NULL;
	file = fopen(argv[1], "r");
	while ((line_size = getline(&buf, &len, file)) != EOF)
	{
		token = strtok(buf, "\r\t\n ");
		strcpy(command, token);
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, "\r\t\n ");
			num = atoi(token);
			p_func = get_op(command);
			if (p_func == NULL)
				return;
			p_func(&first_node, line_number);
		}
	}
	return;
}
