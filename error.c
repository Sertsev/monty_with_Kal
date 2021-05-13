#include "monty.h"
/**
  * case_error_1 - functiont that execute one case error depend of the optino.
  * @ID: Date of input
  * @structure: double pointer of input
  * @ln_num: number of line
  * @data: pointer of input
  **/
void case_error_1(stack_t **structure, unsigned int ln_num, unsigned int data)
{
	switch (data)
			{
				case 1:
					fprintf(stderr, "Error: malloc failed\n");
					break;
				case 2:
					fprintf(stderr, "L%u: usage: push integer\n", ln_num);
					break;
				case 3:
					fprintf(stderr, "L%u: can't print, stack empty\n", ln_num);
					break;
				case 4:
					fprintf(stderr, "L%u: can't pop an empty stack\n", ln_num);
					break;
				case 5:
					fprintf(stderr, "L%u: can't swap, stack too short\n", ln_num);
					break;
				case 6:
					fprintf(stderr, "L%u: can't add, stack too short\n", ln_num);
					break;
			}
	free_all(structure);
	exit(EXIT_FAILURE);
}
