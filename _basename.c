#include "shell.h"

/**
 * _basename - like basename()
 * @path: path to file
 *
 * Return: filename
 */

char *_basename(char *path)
{
	char *last_sep;
	char *current_sep;

	last_sep = NULL;
	current_sep = path;
	while (*current_sep != '\0')
	{
		if (*current_sep == '/')
		{
			last_sep = current_sep;
		}
		current_sep++;
	}
	if (last_sep != NULL)
	{
		return ((char *)last_sep + 1);
	}
	else
	{
		return (path);
	}
}

