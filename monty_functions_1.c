#include "monty.h"


/**
 * _push_ - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @line_num: Interger representing the line number of of the opcode.
 */

void _push_(stack_t **new_node, __attribute__((unused))unsigned int line_num)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}


/**
 * _pall_ - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: line number of  the opcode.
 */

void _pall_(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	(void) line_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * _pop_ - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */

void _pop_(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		more_errors(7, line_num);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * prnt_int - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */

void prnt_int(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		more_errors(6, line_num);
	printf("%d\n", (*stack)->n);
}
