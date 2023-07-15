#include "shell.h"

/**
 * _argslen - like strlen()
 * @str: string input
 *
 * Return: strlen()
 */

size_t _argslen(char **str)
{
	size_t len;

	len = 0;

	while (str[len] != NULL)
	{
		len++;
	}
	return (len);
}
