#include "kash.h"

/**
 * kash_builtin - performs built-in command
 *
 * @av: argument vector
 *
 * Return: 0 if command is built-in, 1 if otherwise
 */

int kash_builtin(char **av)
{
	builtin com[] = {
		{"exit", kash_exit},
		{"cd", kash_cd}
	}


}
