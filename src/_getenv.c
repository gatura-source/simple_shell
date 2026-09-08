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
	char **env;

	if (envariable == NULL || *envariable == '\0')
	{
		return (NULL);
	}
	len = _strlen(envariable);
	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(envariable, *env, len) == 0 && (*env)[len] == '=')
		{
			return (*env + len + 1);
		}
	}
	return (NULL);
}
