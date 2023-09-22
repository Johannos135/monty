#include "monty.h"

/**
 * _rotl - rotates the first element to the bottom and  the second to the top
 *
 * @head_s: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _rotl(stack_t **head_s, unsigned int cline)
{
	stack_t *aux1 = NULL;
	stack_t *aux2 = NULL;
	(void)cline;

	if (*head_s == NULL)
		return;

	if ((*head_s)->next == NULL)
		return;

	aux1 = (*head_s)->next;
	aux2 = *head_s;

	for (; aux2->next != NULL; aux2 = aux2->next)
		;

	aux1->prev = NULL;
	aux2->next = *head_s;
	(*head_s)->next = NULL;
	(*head_s)->prev = aux2;
	*head_s = aux1;
}

/**
 * _rotr - reverse the stack
 *
 * @head_s: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _rotr(stack_t **head_s, unsigned int cline)
{
	stack_t *aux = NULL;
	(void)cline;

	if (*head_s == NULL)
		return;

	if ((*head_s)->next == NULL)
		return;

	aux = *head_s;

	for (; aux->next != NULL; aux = aux->next)
		;

	aux->prev->next = NULL;
	aux->next = *head_s;
	aux->prev = NULL;
	(*head_s)->prev = aux;
	*head_s = aux;
}
