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
	char *cmd_path;
	char *p;
	char *c;

	command = _basename(command);
	if (_strcmp(command, "exit") == 0)
	{
		exit(0);
	}
	c = (char *)err_malloc(sizeof(char) * 10);
	path = (char *)err_malloc(sizeof(char) * 10);
	path = getenv("PATH");
	p = (char *)err_malloc(sizeof(char) * _strlen(path));
	_strcpy(p, path);
	dir = strtok(p, ":");
	cmd_path = (char *)err_malloc(sizeof(char) * 100);

	while (dir != NULL)
	{
		_strcpy(cmd_path, dir);
		_strncat(cmd_path, "/", 1);
		_strncat(cmd_path, command, _strlen(command));
		/**
		 * check if command exists
		 */
		if (access(cmd_path, X_OK) == 0)
		{
			c = cmd_path;
			return (c);
		}
		dir = strtok(NULL, ":");
		bzero(cmd_path, 100);
	}
	free(p);
	free(cmd_path);
	return (c);
}
