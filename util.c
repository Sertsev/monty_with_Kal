#include "monty.h"
/**
 * is_num - Verify if the string is a number
 * @token: String to verify
 *
 * Return: Return a int
 */

int is_num(char *token)
{
	int i = 0, res = 1;

	while (token[i] != '\0')
	{
		if ((token[i] >= 48 && token[i] <= 57) || token[i] == 45)
		{
			i++;
			continue;
		}
		else
			return (res = 0);
		i++;
	}
	return (res);
}
/**
 * strcmp_num - Compare the first element of string with a #
 * @str: The string
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int strcmp_num(char *str)
{
	char cmp = str[0];

	if (cmp == '#')
		return (0);
	else
		return (1);
}
