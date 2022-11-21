#include "monty.h"
int num;

void _open(char **argv)
{
	void (*p_func)(stack_t **, unsigned int);
	char *buf = NULL, *token = NULL, command[1024];
	size_t len = 0;
	unsigned int line_number = 1;
	stack_t *first_node = NULL;
	FILE *file = NULL;
	ssize_t check;

	printf("2\n");
	file = fopen(argv[1], "r");
	printf("%s\n", argv[1]);
	printf("3\n");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	printf("4\n");
	check = getline(&buf, &len, file);
	printf("%ld\n", check);
	while (getline(&buf, &len, file) != -1)
	{
		printf("1");
		token = strtok(buf, "\t\n ");
		if (token == NULL)
      		continue;
		strcpy(command, token);
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, "\t\n ");
			if (token == NULL || isdigit(token) != 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n",
					line_number);
				exit(EXIT_FAILURE);
			}
			num = atoi(token);
			p_func = get_op(command);
			p_func(&first_node, line_number);
		}
		else
		{
			p_func = get_op(command);
			p_func(&first_node, line_number);
		}
		printf("1");
		line_number++;
	}
	fclose(file);
	if (buf != NULL)
		free(buf);
	free_stack(first_node);
}
