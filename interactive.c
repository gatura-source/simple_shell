#include "shell.h"

/**
 * inte - for interactive mode
 * @ac: args counter
 * @av: args vector
 *
 * Return: status
 */

int inte(int ac, char *av[], char *en[])
{
	char **arguments;
	char *lineptr;
	size_t len;
	char *input_buffer;
	char *path;

	lineptr = NULL;
	len = 0;
	while (TRUE)
	{
		type_prompt();
		if (getline(&lineptr, &len, stdin) == -1)
		{
			break;
		}
		input_buffer = eof(lineptr);
		arguments = get_tokens(input_buffer);
		if (arguments == NULL)
		{
			continue;
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
	}
	free(path);
	free(lineptr);
	free_tokens(arguments);
	ac = 0;
	return (ac);
}
