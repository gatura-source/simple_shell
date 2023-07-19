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
	char *path;
	char *input_buffer;

	lineptr = NULL;
	len = 0;
	if (getline(&lineptr, &len, stdin) == -1)
	{
		fatal(av[0]);
		exit(0);
	}
	input_buffer = eof(lineptr);
	arguments = get_tokens(input_buffer);
	if (arguments == NULL)
	{
		exit(0);
	}
	path = _path(arguments[0]);
	if (path != NULL)
	{
		if (execute(path, arguments, NULL) == -1)
		{
			perror(av[0]);
		}
	}
	free(path);
	free(lineptr);
	free(arguments);
	ac = 0;
	return (ac);
}

