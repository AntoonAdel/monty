#include "monty.h"

/**
 * open_my_file - opens a file
 * @filename: the file namepath
 * Return: void
 */

void open_my_file(char *filename)
{
	FILE *f = fopen(filename, "r");

	if (filename == NULL || f == NULL)
		_errors_(2, filename);

	read_my_file(f);
	fclose(f);
}


/**
 * read_my_file - reads a file
 * @f: pointer to file descriptor
 * Return: void
 */

void read_my_file(FILE *f)
{
	int line_num, format = 0;
	char *buffer = NULL;
	size_t length = 0;

	for (line_num = 1; getline(&buffer, &length, f) != -1; line_num++)
	{
		format = analyse_line(buffer, line_num, format);
	}
	free(buffer);
}


/**
 * analyse_line - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_num: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int analyse_line(char *buffer, int line_num, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		_errors_(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_the_func(opcode, value, line_num, format);
	return (format);
}

/**
 * find_the_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_the_func(char *opcode, char *value, int ln, int format)
{
	int n;
	int star;

	instruction_t func_list[] = {
		{"push", _push_},
		{"pall", _pall_},
		{"pint", prnt_int},
		{"pop", _pop_},
		{"nop", _nop_},
		{"swap", _swap_},
		{"add", _add_},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (star = 1, n = 0; func_list[n].opcode != NULL; n++)
	{
		if (strcmp(opcode, func_list[n].opcode) == 0)
		{
			call_func(func_list[n].f, opcode, value, ln, format);
			star = 0;
		}
	}
	if (star == 1)
		_errors_(3, ln, opcode);
}


/**
 * call_func - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_func(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int star;
	int n;

	star = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			star = -1;
		}
		if (val == NULL)
			_errors_(5, ln);
		for (n = 0; val[n] != '\0'; n++)
		{
			if (isdigit(val[n]) == 0)
				_errors_(5, ln);
		}
		node = create_new_node(atoi(val) * star);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			adding_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
