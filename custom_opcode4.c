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
	stack_t *valeur1 = NULL;
	stack_t *valeur2 = NULL;
	(void)cline;

	if (*head_s == NULL)
		return;

	if ((*head_s)->next == NULL)
		return;

	valeur1 = (*head_s)->next;
	valeur2 = *head_s;

	for (; valeur2->next != NULL; valeur2 = valeur2->next)
		;

	valeur1->prev = NULL;
	valeur2->next = *head_s;
	(*head_s)->next = NULL;
	(*head_s)->prev = valeur2;
	*head_s = valeur1;
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
	stack_t *valeur = NULL;
	(void)cline;

	if (*head_s == NULL)
		return;

	if ((*head_s)->next == NULL)
		return;

	valeur = *head_s;

	for (; valeur->next != NULL; valeur = valeur->next)
		;

	valeur->prev->next = NULL;
	valeur->next = *head_s;
	valeur->prev = NULL;
	(*head_s)->prev = valeur;
	*head_s = valeur;
}
