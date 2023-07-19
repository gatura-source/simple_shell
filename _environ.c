#include "shell.h"

/**
 * _env - like env()
 *
 *
 * Return: var or NULL
 */


int _env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		_puts(environ[i]);
		_putchar('\n');
	}
	return (0);
}
