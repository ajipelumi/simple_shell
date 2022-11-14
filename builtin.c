#include "kash.h"

/**
 * kash_exit - exit shell
 *
 * @av: argument vector
 *
 * Return: void
 */

void kash_exit(__attribute__((unused)) char **av)
{
	exit(0);
}

/**
 * kash_cd - change directory
 *
 * @av: argument vector
 *
 * Return: void
 */

void kash_cd(char **av)
{
	int ret;

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
 * @av: argument vector
 *
 * Return: void
 */

void kash_env(__attribute__((unused)) char **av)
{
	extern char **environ;
	int i, len;

	/* iterate through our environment variables */
	for (i = 0; environ[i]; i++)
	{
		/* find string length */
		len = _strlen(environ[i]);
		/* write to standard output */
		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 1); /* new line */
	}
}
