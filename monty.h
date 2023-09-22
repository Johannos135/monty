#ifndef _MONTY_
#define _MONTY_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - head_s linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: head_s linked list node structure
 * for stack, queues, LIFO, FIFO  project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO  project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct globals - contains all the useful stuff
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: head_s linked list
 * @filed: file descriptor
 * @buffer: input text
 *
 * Description: head_s linked list node structure
 * for stack, queues, LIFO, FIFO  project
 */
typedef struct globals
{
	int lifo;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *filed;
	char *buffer;
} global_t;

extern global_t gl_var;

void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **head_s, unsigned int cline);
void _pop(stack_t **head_s, unsigned int cline);
void _swap(stack_t **head_s, unsigned int cline);
void _queue(stack_t **head_s, unsigned int cline);
void _stack(stack_t **head_s, unsigned int cline);
void _add(stack_t **head_s, unsigned int cline);
void _nop(stack_t **head_s, unsigned int cline);
void _sub(stack_t **head_s, unsigned int cline);
void _div(stack_t **head_s, unsigned int cline);
void _mul(stack_t **head_s, unsigned int cline);
void _mod(stack_t **head_s, unsigned int cline);
void _pchar(stack_t **head_s, unsigned int cline);
void _pstr(stack_t **head_s, unsigned int cline);
void _rotl(stack_t **head_s, unsigned int cline);
void _rotr(stack_t **head_s, unsigned int cline);


void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);


int _switch_str(char *s, char c);
char *fun_strtok(char *s, char *d);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int vch_v, unsigned int size);
int _strcmp(char *s1, char *s2);


stack_t *add_at_end(stack_t **head, const int n);
stack_t *add_node(stack_t **head, const int n);
void free_up_list(stack_t *head);


void free_gl_var(void);

#endif
