#include "monty.h"

/**
 * _push - Inserts a node(elemento) to a stack (queue)
 * @stack: Element at the top of the stack
 * @line_number: Constant integer value in structure
 * Return: 0 on success
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int num = 0;
	(void)line_number;
	if (!stack)
	{
		exit(1);
	}
	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (new_node == NULL)
		malloc_error();
	num = atoi(handle.token2);
	new_node->n = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!*stack)
	{
		*stack = new_node;
		return;
	}
	new_node->next = *stack;
	(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * _pall - Function that print the elements of a stack
 * @stack: Element at the top of the stack (head)
 * @line_number: Constant int value in the structure
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;
	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
	*stack = tmp;
}

/**
 * _pint - Prints the value at the top of the stack
 * @stack: Element at the top the stack (head)
 * @line_number: Cantsant int value in the structure
 * Return: Void
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (tmp != NULL)
		printf("%d\n", tmp->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * _pop - Function that deletes the value at top of stack
 * @stack: Element at the top of the stack (head)
 * @line_number: Constant int value in the structure
 * Return: Void
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*stack == NULL)
		pop_error(line_number);

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);

	if (*stack)
		(*stack)->prev = NULL;
}

/**
 * _swap - Function that swaps the top 2 elements of stack
 * @stack: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: Void
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	int tmp;
	stack_t *current = *stack;
	int count = 0;

	while (current)
	{
		count++;
		current = current->next;
	}
	if (count < 2)
	{
		if (*stack == NULL || (*stack)->next == NULL)
			swap_error(line_number);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

