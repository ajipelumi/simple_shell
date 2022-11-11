#include "kash.h"

/**
 * kash_exit - exit shell
 *
 * @av: argument vector
 *
 * Return: void
 */

void kash_exit(char **av)
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

	if (av[1] == NULL)
	{
		av[1] = "$HOME";
	}
	if (av[1] == "-")
	{
		av[1] =
	}
	ret = chdir(av[1]);
	if (ret == -1)
	{
		perror("Error");
	}
}
