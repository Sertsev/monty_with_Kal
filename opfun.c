#include "monty.h"

/**
  * push - Function that add an item to stack
  * @stack : pointer of input
  * @line_number: Number of a line
  * @value : int of input
  **/

void push(stack_t **stack, unsigned int line_number, unsigned int value)
{
	stack_t *aux;
	unsigned int data = 0;

	aux = malloc(sizeof(aux));
	if (aux == NULL)
	{
		data = 1;
		case_error_1(stack, line_number, data);
	}
	if (*stack == NULL)
	{
		*stack = aux;
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
		(*stack)->n = value;
	}
	else
	{
		aux->next = *stack;
		(*stack)->prev = aux;
		aux->prev = NULL;
		aux->n = value;
		*stack = aux;
	}
}

/**
 * pall - Function that print date in the screen
 * @stack : pointer of input
 * @line_number: Number of a line
 * @value :  int of input
 * @stack: double pointer of input
 */

void pall(stack_t **stack, unsigned int line_number, unsigned int value)
{
	size_t count = 0;
	stack_t *aux = *stack;

	line_number = line_number;
	value = value;
	if (!stack)
		exit(EXIT_SUCCESS);
	for (count = 0; aux != NULL; count++)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
