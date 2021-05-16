#include "monty.h"
/**
 * delete_dnodeint_at_index - frees memory from a given index
 * @head: pointer to the first node
 * @idx: index of the node to delete
 * Return: 1 on succes, else -1
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int idx)
{
	unsigned int count = 0;
	stack_t *temp = *head, *next_add;

	if (head == NULL || *head == NULL)
		return (-1);
	while (temp)
	{
		if (count == idx - 1)
		{
			if (temp == NULL)
				return (-1);
			next_add = (temp->next)->next;
			if (temp->next->next != NULL)
				temp->next->next->prev = temp;
			free(temp->next);
			temp->next = next_add;
			return (1);
		}
		else if (idx == 0)
		{
			*head = (*head)->next;
			if (temp->next != NULL)
				temp->next->prev = NULL;
			else
				*head = NULL;
			free(temp);
			return (1);
		}
		temp = temp->next;
		count++;
	}
	return (-1);
}
/**
 * add_dnodeint_end - adds a node at the end of the dlinked list
 * @head: pointer to the first node of the list
 * @n: numeber to fill the node
 * Return: address of the new element or NULL if failed
 */
stack_t *add_dnodeint_end(stack_t **head, int n)
{
	stack_t *temp, *new_node;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	if (!*head)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
		temp->next = new_node;
		return (new_node);
}
