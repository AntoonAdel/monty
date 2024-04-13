#ifndef MONTY
#define MONTY

#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);


void open_my_file(char *filename);
int analyse_line(char *buffer, int line_num, int format);
void read_my_file(FILE *f);
int chars_length(FILE *f);
void find_the_func(char *opcode, char *value, int ln, int format);
stack_t *create_new_node(int num);
void free_the_nodes(void);
void _push_(stack_t **stack, unsigned int line_num);
void _pall_(stack_t **stack, unsigned int line_num);
void add_to_queue(stack_t **stack, unsigned int line_num);
void call_func(op_func func, char *op, char *val, int ln, int format);
void prnt_int(stack_t **stack, unsigned int line_num);
void _pop_(stack_t **stack, unsigned int line_num);
void _swap_(stack_t **stack, unsigned int line_num);
void _add_(stack_t **stack, unsigned int line_num);
void _nop_(stack_t **stack, unsigned int line_num);

void prnt_char(stack_t **stack, unsigned int line_num);
void prnt_str(stack_t **stack, unsigned int line_num);
void _errors_(int error_code, ...);
void more_errors(int error_code, ...);
void string_errors(int error_code, ...);

#endif
