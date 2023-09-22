#include "monty.h"

/**
 * _queue - sets the format of the data to a queue (FIFO)
 *
 * @head_s: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _queue(stack_t **head_s, unsigned int cline)
{
	(void)head_s;
	(void)cline;

	gl_var.lifo = 0;
}

/**
 * _stack - sets the format fo the data to a stack (LIFO)
 *
 * @head_s: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _stack(stack_t **head_s, unsigned int cline)
{
	(void)head_s;
	(void)cline;

	gl_var.lifo = 1;
}

/**
 * _add - adds the top two elements of the stack
 *
 * @head_s: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _add(stack_t **head_s, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *head_s;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		free_gl_var();
		exit(EXIT_FAILURE);
	}

	aux = (*head_s)->next;
	aux->n += (*head_s)->n;
	_pop(head_s, cline);
}

/**
 * _nop - doesn't do anythinhg
 *
 * @head_s: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _nop(stack_t **head_s, unsigned int cline)
{
	(void)head_s;
	(void)cline;
}

/**
 * _sub - subtracts the top element to the second top element of the stack
 *
 * @head_s: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _sub(stack_t **head_s, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *head_s;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cline);
		free_gl_var();
		exit(EXIT_FAILURE);
	}

	aux = (*head_s)->next;
	aux->n -= (*head_s)->n;
	_pop(head_s, cline);
}
