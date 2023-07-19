#include "shell.h"

/**
 * _getenv - like getenv()
 * @envariable: env variable that we are looking
 *
 * Return: var or NULL
 */


char **_getenv(char *envariable)
{

	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strcmp(envariable, environ[i]) == 0)
		{
			return (&environ[i]);
		}
	}
	return (NULL);
}
