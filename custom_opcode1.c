#include "monty.h"

/**
 * _push - add an element to the stack
 *
 * @head_s: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _push(stack_t **head_s, unsigned int cline)
{
	int n, j;

	if (!gl_var.arg)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "usage: push integer\n");
		free_gl_var();
		exit(EXIT_FAILURE);
	}

	for (j = 0; gl_var.arg[j] != '\0'; j++)
	{
		if (!isdigit(gl_var.arg[j]) && gl_var.arg[j] != '-')
		{
			dprintf(2, "L%u: ", cline);
			dprintf(2, "usage: push integer\n");
			free_gl_var();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(gl_var.arg);

	if (gl_var.lifo == 1)
		add_node(head_s, n);
	else
		add_at_end(head_s, n);
}

/**
 * _pall - prints all values on the stack
 *
 * @head_s: head of the linked list
 * @cline: line numbers
 * Return: no return
 */
void _pall(stack_t **head_s, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *head_s;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 *
 * @head_s: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _pint(stack_t **head_s, unsigned int cline)
{
	(void)cline;

	if (*head_s == NULL)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "can't pint, stack empty\n");
		free_gl_var();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head_s)->n);
}

/**
 * _pop - removes the top element of the stack
 *
 * @head_s: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _pop(stack_t **head_s, unsigned int cline)
{
	stack_t *aux;

	if (head_s == NULL || *head_s == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", cline);
		free_gl_var();
		exit(EXIT_FAILURE);
	}
	aux = *head_s;
	*head_s = (*head_s)->next;
	free(aux);
}

/**
 * _swap - swaps the top two elements of the stack
 *
 * @head_s: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _swap(stack_t **head_s, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *head_s;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", cline);
		free_gl_var();
		exit(EXIT_FAILURE);
	}

	aux = *head_s;
	*head_s = (*head_s)->next;
	aux->next = (*head_s)->next;
	aux->prev = *head_s;
	(*head_s)->next = aux;
	(*head_s)->prev = NULL;
}
