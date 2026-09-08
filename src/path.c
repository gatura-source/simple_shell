#include "shell.h"

/**
 * _path - handles path
 * @command: command passed
 *
 * Return: 0 if command found, 1 else
 */

char *_path(char *command)
{
	char *path;
	char *dir;
	char cmd_path[PATH_MAX];
	char *p;
	char *found_path;
	size_t dirlen;
	size_t cmdlen;

	command = _basename(command);
	if (command == NULL)
	{
		return (NULL);
	}
	if (_strcmp(command, "exit") == 0)
	{
		return (NULL);
	}
	path = _getenv("PATH");
	if (path == NULL)
	{
		return (NULL);
	}
	p = (char *)err_malloc(_strlen(path) + 1);
	if (p == NULL)
	{
		return (NULL);
	}
	_strcpy(p, path);
	cmdlen = _strlen(command);
	dir = strtok(p, ":");
	while (dir != NULL)
	{
		dirlen = _strlen(dir);
		if (dirlen + cmdlen + 2 > PATH_MAX)
		{
			dir = strtok(NULL, ":");
			continue;
		}
		_memset(cmd_path, 0, PATH_MAX);
		_strcpy(cmd_path, dir);
		_strncat(cmd_path, "/", 1);
		_strncat(cmd_path, command, cmdlen);
		if (access(cmd_path, X_OK) == 0)
		{
			found_path = _strdup(cmd_path);
			free(p);
			return (found_path);
		}
		dir = strtok(NULL, ":");
	}
	free(p);
	return (NULL);
}
