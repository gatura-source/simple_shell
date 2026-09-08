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
	pid_t pid;
	int wstatus;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0)
	{
		execve(command, args, envp);
		_exit(127);
	}
	if (waitpid(pid, &wstatus, 0) == -1)
	{
		perror("waitpid");
		return (-1);
	}
	if (WIFEXITED(wstatus))
	{
		return (WEXITSTATUS(wstatus));
	}
	return (-1);
}

