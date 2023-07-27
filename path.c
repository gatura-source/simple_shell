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

	command = _basename(command);
	if (_strcmp(command, "exit") == 0)
	{
		_exit(0);
	}
	if (_strcmp(command, "env") == 0)
	{
		_env();
	}
	path = _getenv("PATH");
	p = (char *)err_malloc(sizeof(char) * _strlen(path) + 1);
	_strcpy(p, path);
	dir = strtok(p, ":");
	while (dir != NULL)
	{
		_strcpy(cmd_path, dir);
		_strncat(cmd_path, "/", 1);
		_strncat(cmd_path, command, _strlen(command));
		if (access(cmd_path, X_OK) == 0)
		{
			found_path = _strdup(cmd_path);
			free(p);
			return (found_path);
		}
		dir = strtok(NULL, ":");
		_memset(cmd_path, 0, PATH_MAX);
	}
	free(p);
	return (NULL);
}
