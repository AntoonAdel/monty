#include "monty.h"

/**
 * prnt_char - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */

void prnt_char(stack_t **stack, unsigned int line_num)
{
	int asci;

	if (stack == NULL || *stack == NULL)
		string_errors(11, line_num);

	asci = (*stack)->n;
	if (asci < 0 || asci > 127)
		string_errors(10, line_num);
	printf("%c\n", asci);
}

/**
 * prnt_str - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */

void prnt_str(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	int asci;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		asci = temp->n;
		if (asci <= 0 || asci > 127)
			break;
		printf("%c", asci);
		temp = temp->next;
	}
	printf("\n");
}
