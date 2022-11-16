#include "kash.h"

/**
 * _getenv - get environment variable
 *
 * @name: name of the variable
 *
 * Return: environment value
 */

char *_getenv(char *name)
{
	extern char **environ;
	char *env = NULL;
	unsigned int a = 0, b = 0, c = 0, d = 0;

	while (environ[a] != NULL) /* loop throughs env variables */
	{
		while (name[c] != '\0') /* loop through PATH */
		{
			if (name[c] == environ[a][b])
			{
				/* until PATH variable is found */
				c++, b++;
			}
			else
				break; /* exit the while loop */
		}
		if (name[c] == '\0') /* PATH is found */
		{
			b++; /* goes to the value after '=' */
			env = malloc(sizeof(char) * _strlen(environ[a]) - b + 1);
			while (environ[a][b] != '\0') /* loop through PATH value */
			{
				/* store PATH value in allocated memory */
				env[d] = environ[a][b];
				d++, b++;
			}
			return (env); /* return pointer to value of PATH */
		}
		else
			c = b = 0, a++; /* loops through environment until PATH is found */
	}
	free(env);
	return (NULL); /* return NULL if no PATH */
}

/**
 * sig_handler - Ignore singal input for Ctrl + C
 *
 * @num: value of SIGINT
 *
 * Return: void
 */

void sig_handler(int num)
{
	/* when Ctrl + C is signalled in kash */
	if (num == SIGINT)
	{
		write(1, "\n($) ", 4); /* writes our prompt instead of exiting */
	}
}

/*
 * kash_path - finds the path of a specific command
 *
 * @command: name of command
 *
 * Return: path name with command
 */

char *kash_path(char *command)
{
	char *name = "PATH";
	char *path, *tok, *delim = "=,:";
	char *str[8];
	struct stat sb;
	int i = 0;

	path = _getenv(name); /* get path value */
	tok = strtok(path, delim); /* split directories into strings */
	tok = strtok(NULL, delim); /* eliminates "PATH=" */
	while (tok != NULL) /* loop until end of PATH */
	{
		str[i] = NULL;
		str[i] = _strdup(tok); /* copy directory in PATH */
		str[i] = _strcat(str[i], command); /* append command */
		if (command[0] == '/') /* if command is a directory */
		{
			break; /* exit the loop */
		}
		if (_strcmp(command, "./") == 0) /* if command is a directory */
		{
			break; /* exit the loop */
		}
		if (stat(str[i], &sb) == 0) /* locate the command in PATH */
		{
			return (str[i]); /* return appended command */
		}
		else
		{
			i++;
		}
		tok = strtok(NULL, delim); /* goes to the next directory */
	}
	free(str[i]);
	free(path);
	return (command); /* return command */
}
