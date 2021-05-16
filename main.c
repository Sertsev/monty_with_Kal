#include "monty.h"

FILE *usage_error(int arc, char *arv)
{
	FILE *file_op;

	if (arc != 2)
		simple_err(0, arv);
	file_op = fopen(arv, "r");
	if (!file_op)
		simple_err(1, arv);
	return (file_op);
}

/**
 * main - engine to integrate the monty interpreter
 * @arc: argument count
 * @arv: argument vector
 * Return: 0 on success otherwise EXIT_FAILURE
 */

int main(int arc, char *arv[])
{
	instruction_t ins_arr[] = {{"push", _push}, {"pall", _pall}, {"pint", _pint},
		{"nop", _nop}, {"pop", _pop}, {"add", _add}, {"swap", _swap}, {"sub", _sub},
		{"div", _div}, {"mul", _mul}, {"pchar", _pchar}, {"pstr", _pstr},
		{"mod", _mod}, {"#", _nop}, {"rotr", _rotr},  {NULL, NULL}};
	FILE *file_op = usage_error(arc, arv[1]);
	stack_t *stack = NULL;
	char *token, *token_push, *buff = NULL;
	size_t i = 0, line = 1, size = Buffsize;

	value[1] = 0;
	while (getline(&buff, &size, file_op) != EOF)
	{token = strtok(buff, " \t\n\r");
		if (token == NULL)
		{line++;
			continue; }
		i = 0;
		if (strcmp_num(buff) == 0)
			token = "#";
		if (strcmp(token, "stack") == 0)
		{line++, value[1] = 0;
			continue; }
		else if (strcmp(token, "queue") == 0)
		{line++, value[1] = 1;
			continue; }
		while (ins_arr[i].opcode != NULL)
		{
			if (strcmp(token, ins_arr[i].opcode) == 0)
			{
				if (strcmp(token, "push") == 0)
				{token_push = strtok(NULL, " \t\n\r");
					if (!token_push || is_num(token_push) == 0)
						free_err(file_op, buff, stack, line, 0, token);
					value[0] = atoi(token_push); }
				ins_arr[i].f(&stack, line);
				break; }
			else if (!ins_arr[i + 1].opcode)
				free_err(file_op, buff, stack, line, 1, token);
			i++; }
		line++; }
	fclose(file_op), free_dlistint(stack), free(buff);
	return (0); }

/**
 * free_dlistint - frees memory from a dlinked list
 * @head: pointer to the first node
 **/

void free_dlistint(stack_t *head)
{
	stack_t *next, *current;

	current = head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

/**
 * simple_err- Function to handle simple errors
 * @del_code: Code of deletion
 * @arv: Name of the file
 **/

void simple_err(int del_code, char *arv)
{
	if (del_code == 0)
		fprintf(stderr, "USAGE: monty file\n");
	else if (del_code == 1)
		fprintf(stderr, "Error: Can't open file %s\n", arv);
	exit(EXIT_FAILURE);
}

/**
 * free_err - Function to handle errors that need free
 * @file: The file to close
 * @bff: The buffer to free
 * @stk: The stack to free
 * @lne: the number of the line that had the error
 * @cde: Code of deletion
 * @tok: Pycode
 **/

void free_err(FILE *file, char *bff, stack_t *stk, int lne, int cde, char *tok)
{
	if (cde == 0)
		fprintf(stderr, "L%d: usage: push integer\n", lne);
	else if (cde == 1)
		fprintf(stderr, "L%d: unknown instruction %s\n", lne, tok);
	fclose(file);
	free(bff);
	free_dlistint(stk);
	exit(EXIT_FAILURE);
}
