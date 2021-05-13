#include "monty.h"

/**
 * main - a function to interprete of commands input since screen
 * @argc: arguments count
 * @argv: arguments input
 *
 * Return: Always zero
 */

int main(int argc, char *argv[])
{
	FILE *ID;
	char *line = NULL, *Token = NULL;
	stack_t *structure = NULL;
	unsigned int count = 1;
	int test = 0;
	size_t bufsize = 1024;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

	ID = fopen(argv[1], "r");

	if (ID == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &bufsize, ID)) != -1)
	{
		Token = strtok(line, " \n");
		if (Token == NULL)
		{continue; }
		test = get_comparation(Token, &structure, count);
		if (test == -1)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", count, Token);
			free_all(&structure);
			fclose(ID);
			exit(EXIT_FAILURE);
		}
		count++;
	}
	fclose(ID);
	free(line);
	return (EXIT_SUCCESS);
}

/**
  * free_all - function that free the memory of the stack
  * @stack: Estructure
  **/

void free_all(stack_t **stack)
{
	stack_t *head;

	while (*stack != NULL)
	{
		head = *stack;
		*stack = (*stack)->next;
		free(head);
	}
}

/**
  * get_comparation - compare the function whit the data of input (entrada)
  * @Token: the function
  * @structure: double poinetr of input
  * @ln_num: line of the bytecode
  * Return: the function
  **/
int get_comparation(char *Token, stack_t **structure, unsigned int ln_num)
{
	instruction_t opfun[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	
	int value = 0, data = 0;
	int count = 0, status = 0;

	while (opfun[count].opcode && count <= 1)
	{
		if (strcmp(opfun[count].opcode, "push") != 0)
		{
			if (strcmp(opfun[count].opcode, Token) == 0)
			{opfun[count].f(structure, ln_num, value), status = 1; }
		}
		else if (strcmp(opfun[count].opcode, Token) == 0)
		{
			Token = strtok(NULL, " \n");
			if (Token == NULL)
			{
				data = 2;
				case_error_1(structure, ln_num, data);
			}
			if ((*Token >= 48 && *Token <= 57) && (Token != NULL))
			{value = atoi(Token); }
			opfun[count].f(structure, ln_num, value), status = 1;
			return (0);
		}
		count++;
	}
	if (count == 2 && status == 0)
	{return (-1); }
	else
	{return (0); }
}
