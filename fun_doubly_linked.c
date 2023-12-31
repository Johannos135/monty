#include "monty.h"

/**
 *add_at_end - add a note at the end of the head_s link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a head_s linked list
 */
stack_t *add_at_end(stack_t **head, const int n)
{
	stack_t *temp, *valeur;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_gl_var();
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	/*Careful with the first time*/
	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	valeur = *head;
	while (valeur->next)
		valeur = valeur->next;
	temp->next = valeur->next;
	temp->prev = valeur;
	valeur->next = temp;
	return (valeur->next);
}

/**
 *add_node - add a note at the begining of the head_s link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a head_s linked list
 */
stack_t *add_node(stack_t **head, const int n)
{
	stack_t *temp;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_gl_var();
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	/*Careful with the first time*/
	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	(*head)->prev = temp;
	temp->next = (*head);
	temp->prev = NULL;
	*head = temp;
	return (*head);
}

/**
 * free_up_list - frees the head_s linked list
 *
 * @head: head of the list
 * Return: no return
 */
void free_up_list(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
