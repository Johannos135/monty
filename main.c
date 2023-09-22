#include "monty.h"

global_t gl_var;

/**
 * free_gl_var - frees global variables
 */
void free_gl_var(void)
{
	free_up_list(gl_var.head);
	free(gl_var.buffer);
	fclose(gl_var.filed);
}

/**
 * start_gl_var - initializes the global variables
 *
 * @filed: file descriptor
 */
void start_gl_var(FILE *filed)
{
	gl_var.lifo = 1;
	gl_var.cont = 1;
	gl_var.arg = NULL;
	gl_var.head = NULL;
	gl_var.filed = filed;
	gl_var.buffer = NULL;
}

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *filed;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filed = fopen(argv[1], "r");

	if (filed == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (filed);
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *filed;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	filed = check_input(argc, argv);
	start_gl_var(filed);
	nlines = getline(&gl_var.buffer, &size, filed);
	while (nlines != -1)
	{
		lines[0] = fun_strtok(gl_var.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", gl_var.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_gl_var();
				exit(EXIT_FAILURE);
			}
			gl_var.arg = fun_strtok(NULL, " \t\n");
			f(&gl_var.head, gl_var.cont);
		}
		nlines = getline(&gl_var.buffer, &size, filed);
		gl_var.cont++;
	}

	free_gl_var();

	return (0);
}
