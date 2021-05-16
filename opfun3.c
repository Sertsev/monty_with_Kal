#include "monty.h"
/**
 * _sub - subtract the two first elements of stack
 * @stack: pointer to the top of the stack
 * @line_number: line counter
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int substraction;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	substraction = (*stack)->n;
	(*stack)->next->n -= substraction;
	_pop(stack, line_number);
}
/**
 * _mul - multiply the first two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number : line counter
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int mul;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	mul = (*stack)->n;
	(*stack)->next->n *= mul;
	_pop(stack, line_number);
}
/**
 * _pchar - Print a char with ASCII value
 * @stack: pointer to the top of the stack
 * @line_number: line counter
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int code;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	code = (*stack)->n;
	if (code >= 0 && code <= 127)
	{
		putchar(code);
		putchar(10);
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * _pstr - Print the chars of a stack with ASCII value
 * @stack: pointer to the top of the stack
 * @line_number : line counter
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;
	int code;
	(void)line_number;

	if (!*stack)
		putchar(10);
	else
	{
		aux = *stack;
		while (aux)
		{
			code = aux->n;
			if (code > 0 && code <= 127)
				putchar(code);
			else
				break;
			aux = aux->next;
		}
		putchar(10);
	}
}
/**
 * _rotr - rotates the stack to the bottom
 * @stack: pointer to the top of the stack
 * @line_number: line counter
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		aux = *stack;
		while (aux)
		{
			if (!aux->next)
			{
				value[0] = aux->n;
				aux->prev->next = NULL;
				free(aux);
				break;
			}
			aux = aux->next;
		}
		_push(stack, line_number);
	}
}
