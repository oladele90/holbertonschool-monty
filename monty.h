#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern int num;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
     int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void (*get_op(char *opcode, unsigned int line_number
	      ))(stack_t **, unsigned int);
void push_op(stack_t **first_node, unsigned int line_number);
void _open(char **argv);
int main(int argc, char **argv);
void free_stack(stack_t *first_node);
int num_check(char *token);
void pall_op(stack_t **first_node, unsigned int line_number);
int com_check(char *token, unsigned int line_number);
void ie(unsigned int line_number);
void opf(char **argv);
void pint_op(stack_t **first_node, unsigned int line_number);
void pop_op(stack_t **first_node, unsigned int line_number);
void swap_op(stack_t **first_node, unsigned int line_number);
void add_op(stack_t **first_node, unsigned int line_number);
void nop_op(stack_t **first_node, unsigned int line_number);
#endif
