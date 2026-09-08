#include "shell.h"

/**
 * _isspace - man read the man
 * @c: char input
 *
 * Return: True or False
 */

bool _isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\f' || c == '\v');
}
