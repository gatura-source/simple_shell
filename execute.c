#include "shell.h"

/**
 * execute - calls fork
 * @command: command to execute
 * @args: args to command
 * @envp: env pointer
 *
 * Return: 0 or -1
 */
int execute(char *command, char **args, char **envp)
{
	int wstatus;
	int status;

	if (fork() != 0)
	{
		waitpid(-1, &wstatus, 0);
	}
	else
	{
		status = (execve(command, args, envp));
	}
	return (status);
}

