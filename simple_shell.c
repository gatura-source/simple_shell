#include "shell.h"

/**
 * main - entry point
 * @ac: args counter
 * @av: args vector
 *
 *
 * Return: always 0
 */

int main(int ac, char *av[])
{
	if (!isatty(STDIN_FILENO))
	{
		non_inte(ac, av);
	}
	else
	{
		inte(ac, av);
	}
	return (0);
}
