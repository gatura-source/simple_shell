#include "shell.h"

/**
 * inte - for interactive mode
 * @ac: args counter
 * @av: args vector
 *
 * Return: status
 */

int inte(int ac, char *av[])
{
	char **arguments;
	char *lineptr;
	size_t len;
	char *input_buffer;
	char *path;

	lineptr = NULL;
	len = 0;
	path = (char *)err_malloc(sizeof(char) * 20);
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
		if (_argslen(arguments) != 1)
		{
			fatal(av[0]);
			continue;
		}
		path = arguments[0];
		if (execute(path, arguments, NULL) == -1)
		{
			perror(av[0]);
		}
	}
	free(path);
	free_tokens(arguments);
	ac = 0;
	return (ac);
}
