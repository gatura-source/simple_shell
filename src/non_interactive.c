#include "shell.h"

/**
 * non_inte - for non-interactive mode
 * @ac: args counter
 * @av: args vector
 *
 * Return: 0
 */
int non_inte(int ac, char *av[], char *en[])
{
	char **arguments;
	char *lineptr;
	size_t len;
	char *path;
	char *input_buffer;

	lineptr = NULL;
	len = 0;
	arguments = NULL;
	path = NULL;
	if (getline(&lineptr, &len, stdin) == -1)
	{
		free(lineptr);
		exit(0);
	}
	input_buffer = eof(lineptr);
	if (input_buffer == NULL)
	{
		free(lineptr);
		exit(0);
	}
	arguments = get_tokens(input_buffer);
	if (arguments == NULL)
	{
		free(lineptr);
		exit(0);
	}
	if (_strcmp(arguments[0], "exit") == 0)
	{
		free_tokens(arguments);
		free(lineptr);
		exit(0);
	}
	path = _path(arguments[0]);
	if (path != NULL)
	{
		if (execute(path, arguments, en) == -1)
		{
			perror(av[0]);
		}
	}
	else
	{
		fatal(av[0], arguments[0]);
	}
	free(path);
	free_tokens(arguments);
	free(lineptr);
	ac = 0;
	return (ac);
}

