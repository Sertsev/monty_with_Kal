#include "monty.h"
/**
 * _pop - a new item at the top of the list
 * @stack:  pointer to the top of the stack
 * @line_number: line counter
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	if (!aux->next)
	{
		*stack = NULL;
		free(aux);
	}
	else
	{
		*stack = aux->next;
		aux->next->prev = NULL;
		free(aux);
	}
}
/**
 * _add - add the first two elements of stack
 * @stack: pointer to the top of the stack
 * @line_number: line counter
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int addition;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	addition = (*stack)->n;
	(*stack)->next->n += addition;
	_pop(stack, line_number);
}
/**
 * _div - divide the two first elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line counter
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int division;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	division = (*stack)->n;
	if (division == 0)
	{
		fprintf(stderr, "L%d:division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= division;
	_pop(stack, line_number);
}
/**
 * _mod - computes the rest of the division of the seconf top element
 * @stack: pointer to the top of the stack
 * @line_number: line counter
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int module;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	module = (*stack)->n;
	if (module == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= module;
	_pop(stack, line_number);
}
