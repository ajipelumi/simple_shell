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
	int i;
	builtin com[] = {
		{"exit", kash_exit},
		{"cd", kash_cd},
		{"env", kash_env}
	};

	/* iterate through our struct */
	for (i = 0; com[i].command != NULL; i++)
	{
		if (_strcmp(av[0], com[i].command) == 0) /* if command exists */
		{
			com[i].func(av); /* calls associated function */
			return (0);
		}
	}
	return (1); /* command is not built-in */
}
