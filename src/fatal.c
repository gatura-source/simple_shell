#include "shell.h"

/**
 * fatal - for fatal errors
 * @prog: program name
 * @command: command
 *
 * Return: void
 */

void fatal(char *prog, char *command)
{
	char *message;
	size_t proglen;
	size_t cmdlen;
	size_t total;

	if (prog == NULL)
	{
		prog = "hsh";
	}
	if (command == NULL)
	{
		command = "";
	}
	proglen = _strlen(prog);
	cmdlen = _strlen(command);
	total = proglen + cmdlen + 6 + 12 + 1;

	message = (char *)err_malloc(total);
	if (message == NULL)
	{
		return;
	}
	_strcpy(message, prog);
	_strncat(message, ": 1: ", 5);
	_strncat(message, command, cmdlen);
	_strncat(message, ": not found\n", 12);
	_puts(message);
	free(message);
}
