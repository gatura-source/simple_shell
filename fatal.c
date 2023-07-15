#include "shell.h"

/**
 * fatal - for fatal errors
 * @prog: program name
 *
 * Return: void
 */

void fatal(char *prog)
{
	char *message;

	message = (char *)err_malloc(sizeof(char) * 38);
	_strcpy(message, prog);
	_strncat(message, ": No such file or directory\n", 28);
	_puts(message);
	free(message);
}
