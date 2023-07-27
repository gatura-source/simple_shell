#include "shell.h"

/**
 * _getenv - like getenv()
 * @envariable: env variable that we are looking
 *
 * Return: var or NULL
 */


char *_getenv(char *envariable)
{
	size_t len;

	len = _strlen(envariable);
	if (envariable == NULL || *envariable == '\0')
	{
		return (NULL);
	}

	while (*environ != NULL)
	{
		if (_strncmp(envariable, *environ, len) == 0)
		{
			return (*environ + len + 1);
		}
		environ++;
	}
	return (NULL);
}
