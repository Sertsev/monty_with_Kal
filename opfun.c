#include "monty.h"
/**
 * _push -adds a new item to tr top of a stack
 * @stack: pointer to the top of the stack
 * @line_number: line counter
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *n_node;
	(void)line_number;

	if (value[1] == 0)
	{
		n_node = malloc(sizeof(stack_t));
		if (n_node == NULL)
		{
			fprintf(stderr, "Error: malloc failed");
			exit(EXIT_FAILURE);
		}
		n_node->n = value[0];
		n_node->prev = NULL;
		n_node->next = *stack;

		if (*stack != NULL)
			(*stack)->prev = n_node;
		*stack = n_node;
	}
	else if (value[1] == 1)
		add_dnodeint_end(stack, value[0]);
}
/**
 * _pall - print all elements of stack
 * @stack: pointer to the top of the stack
 * @line_number: line counter
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	if (temp)
	{
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}
/**
 * _pint - prints  the top pof the stack
 * @stack: pointer to the top of the stack
 * @line_number: liner counter
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: Can't print, stacj empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * _swap - swaps the first two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line counter
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int first_n, sec_n;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d : can't swap, stack too showrt\n", line_number);
		exit(EXIT_FAILURE);
	}
	first_n = temp->n;
	sec_n = temp->next->n;
	temp->next->n = first_n;
	temp->n = sec_n;
}
/**
 * _nop - does nothing
 * @stack: pointer to the top of the stack
 * @line_number: line counter
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
