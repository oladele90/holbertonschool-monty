#include "monty.h"

/**
 * _open - opens monty file and executes commands
 * @argv: arguement vector of main file
 * Return: nothing
 */

void _open(char **argv)
{
	void (*p_func)(stack_t **, unsigned int);
	char *buf = NULL, *token = NULL, command[1024];
	size_t len = 0;
	unsigned int line_number = 1;
	stack_t *first_node = NULL;
	FILE *file = NULL;

	file = fopen(argv[1], "r");
	if (file == NULL)
		opf(argv);
	while (getline(&buf, &len, file) != -1)
	{
		token = strtok(buf, "\t\n ");
		if (token == NULL)
			continue;
		strcpy(command, token);
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, "\t\n ");
			if (token == NULL || num_check(token) != 1)
				ie(line_number);
			num = atoi(token);
			p_func = get_op(command, line_number);
			p_func(&first_node, line_number);
		}
		else
		{
			p_func = get_op(command, line_number);
			p_func(&first_node, line_number);
		}
		line_number++;
	}
	fclose(file);
	if (buf != NULL)
		free(buf);
	free_stack(first_node);
}

/**
 * num_check - checks token to see if it is a number
 * @token: token passed to function
 * Return: 1 if it is number of -1 if it is not
 */

int num_check(char *token)
{
	int i;

	if (token == NULL)
		return (-1);
	for (i = 0; token[i] != '\0'; i++)
	{
		if (token[i] != '-' && isdigit(token[i]) == 0)
			return (-1);
	}
	return (1);
}
