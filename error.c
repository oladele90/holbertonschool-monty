#include "monty.h"

/**
 * opf - prints error and exits program if unable to open file
 * @argv: arguement vector passed in
 * Return: nothing
 */

void opf(char **argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	exit(EXIT_FAILURE);
}

/**
 * ie - prints error and exits program if token is not an integer
 * @line_number: current line number of monty file
 * Return: nothing
 */

void ie(unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}
