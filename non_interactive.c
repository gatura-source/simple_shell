#include "shell.h"

/**
 * non_inte - for non-interactive mode
 * @ac: args counter
 * @av: args vector
 *
 * Return: 0
 */
int non_inte(int ac, char *av[])
{
	char **arguments;
	char *lineptr;
	size_t len;
	char *input_buffer;

	lineptr = NULL;
	len = 0;
	getline(&lineptr, &len, stdin);
	input_buffer = eof(lineptr);
	arguments = get_tokens(input_buffer);
	if (arguments == NULL)
	{
		exit(0);
	}
	if (_argslen(arguments) != 1)
	{
		fatal(av[0]);
		exit(-1);
	}
	if (execute(arguments[0], arguments, NULL) == -1)
	{
		perror(av[0]);
	}
	free_tokens(arguments);
	ac = 0;
	return (ac);
}

