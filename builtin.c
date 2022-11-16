#include "kash.h"

/**
 * kash_exit - exit shell
 *
 * @env: environment variables
 * @av: argument vector
 *
 * Return: void
 */

void kash_exit(char **env, char **av)
{
	(void)env;
	(void)av;

	exit(0);
}

/**
 * kash_cd - change directory
 *
 * @env: environment variables
 * @av: argument vector
 *
 * Return: void
 */

void kash_cd(char **env, char **av)
{
	int ret;

	(void)env;

	if (_strcmp(av[1], "\0") == 0)
	{
		av[1] = "$HOME";
	}
	if (_strcmp(av[1], "-") == 0)
	{
		av[1] = "$OLDPWD";
	}

	ret = chdir(av[1]);
	if (ret == -1)
	{
		perror("Error");
	}
}

/**
 * kash_env - prints the current environment
 *
 * @env: environment variables
 * @av: argument vector
 *
 * Return: void
 */

void kash_env(char **env, char **av)
{
	int i, len;

	(void)av;

	/* iterate through our environment variables */
	for (i = 0; env[i]; i++)
	{
		/* find string length */
		len = _strlen(env[i]);
		/* write to standard output */
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1); /* new line */
	}
}

/**
 * kash_builtin - performs built-in command
 *
 * @env: environment variables
 * @av: argument vector
 *
 * Return: 0 if command is built-in, 1 if otherwise
 */

int kash_builtin(char **env, char **av)
{
	int i;
	builtin com[] = {
		{"exit", kash_exit},
		{"cd", kash_cd},
		{"env", kash_env},
		{NULL, NULL}
	};

	/* iterate through our struct */
	for (i = 0; com[i].command != NULL; i++)
	{
		if (_strcmp(av[0], com[i].command) == 0) /* if command exists */
		{
			com[i].func(env, av); /* calls associated function */
			return (0);
		}
	}
	return (1); /* command is not built-in */
}
