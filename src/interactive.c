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
	int status;

	status = 0;
	(void)ac;
	while (TRUE)
	{
		arguments = NULL;
		path = NULL;
		lineptr = NULL;
		len = 0;
		type_prompt();
		if (getline(&lineptr, &len, stdin) == -1)
		{
			free(lineptr);
			break;
		}
		input_buffer = eof(lineptr);
		if (input_buffer == NULL)
		{
			free(lineptr);
			continue;
		}
		arguments = get_tokens(input_buffer);
		if (arguments == NULL)
		{
			free(lineptr);
			continue;
		}
		if (_strcmp(arguments[0], "exit") == 0)
		{
			free_tokens(arguments);
			free(lineptr);
			break;
		}
		path = _path(arguments[0]);
		if (path != NULL)
		{
			if (execute(path, arguments, en) == -1)
			{
				perror(av[0]);
				status = -1;
			}
			free(path);
		}
		else
		{
			fatal(av[0], arguments[0]);
		}
		free_tokens(arguments);
		free(lineptr);
	}
	return (status);
}
