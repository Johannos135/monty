#include "monty.h"

/**
 * _div - divides the second element by the top element of the stack
 *
 * @head_s: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _div(stack_t **head_s, unsigned int cline)
{
	int m = 0;
	stack_t *valeur = NULL;

	valeur = *head_s;

	for (; valeur != NULL; valeur = valeur->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", cline);
		free_gl_var();
		exit(EXIT_FAILURE);
	}

	if ((*head_s)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		free_gl_var();
		exit(EXIT_FAILURE);
	}

	valeur = (*head_s)->next;
	valeur->n /= (*head_s)->n;
	_pop(head_s, cline);
}

/**
 * _mul - multiplies the top element to the second top element of the stack
 *
 * @head_s: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _mul(stack_t **head_s, unsigned int cline)
{
	int m = 0;
	stack_t *valeur = NULL;

	valeur = *head_s;

	for (; valeur != NULL; valeur = valeur->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", cline);
		free_gl_var();
		exit(EXIT_FAILURE);
	}

	valeur = (*head_s)->next;
	valeur->n *= (*head_s)->n;
	_pop(head_s, cline);
}

/**
 * _mod - computes the rest of the division of the second element
 * by the top element of the stack
 *
 * @head_s: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _mod(stack_t **head_s, unsigned int cline)
{
	int m = 0;
	stack_t *valeur = NULL;

	valeur = *head_s;

	for (; valeur != NULL; valeur = valeur->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", cline);
		free_gl_var();
		exit(EXIT_FAILURE);
	}

	if ((*head_s)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		free_gl_var();
		exit(EXIT_FAILURE);
	}

	valeur = (*head_s)->next;
	valeur->n %= (*head_s)->n;
	_pop(head_s, cline);
}
/**
 * _pchar - print the char value of the first element
 *
 * @head_s: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _pchar(stack_t **head_s, unsigned int cline)
{
	if (head_s == NULL || *head_s == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", cline);
		free_gl_var();
		exit(EXIT_FAILURE);
	}
	if ((*head_s)->n < 0 || (*head_s)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", cline);
		free_gl_var();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head_s)->n);
}

/**
 * _pstr - prints the string of the stack
 *
 * @head_s: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _pstr(stack_t **head_s, unsigned int cline)
{
	stack_t *valeur;
	(void)cline;

	valeur = *head_s;

	while (valeur && valeur->n > 0 && valeur->n < 128)
	{
		printf("%c", valeur->n);
		valeur = valeur->next;
	}

	printf("\n");
}
