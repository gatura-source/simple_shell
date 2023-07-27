#include "shell.h"

/**
 * main - entry point
 * @ac: args counter
 * @av: args vector
 *
 *
 * Return: always 0
 */

int main(int ac, char *av[], char *envp[])
{
	if (!isatty(STDIN_FILENO))
	{
		non_inte(ac, av, envp);
	}
	else
	{
		inte(ac, av, envp);
	}
	return (0);
}
