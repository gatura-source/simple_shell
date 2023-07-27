#include "shell.h"

/**
 * check_spaces - like the anme
 * @str: str input
 *
 * Return: t or f
 */

bool check_spaces(char *str)
{
	int i;

	i = 0;
	if (str == NULL || *str == '\0')
	{
		return (true);
	}
	while (*str != '\0')
	{
		if (!_isspace(*str))
		{
			i++;
		}
		str++;
	}
	if (i == 0)
	{
		return (true);
	}
	return (false);
}

