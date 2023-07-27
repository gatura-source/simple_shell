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

	message = (char *)err_malloc(sizeof(char) * 1024);
	_strcpy(message, prog);
	_strncat(message, ":", 1);
	_strncat(message, " ", 1);
	_strncat(message, "1", 1);
	_strncat(message, ": ", 2);
	_strncat(message, command, _strlen(command));
	_strncat(message, ": not found\n", 13);
	_puts(message);
	free(message);
}
