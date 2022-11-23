#include "monty.h"

/**
 * main - takes in arguements and passes them to _open function
 * @argc: arg count
 * @argv: arg vector
 * Return: 0 of exit_failure
 */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	_open(argv);
	return (0);
}
