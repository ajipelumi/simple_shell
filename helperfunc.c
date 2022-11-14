#include "kash.h"

/**
 * _getenv - get environment variable
 *
 * @name: name of the variable
 *
 * Return: environment value
 */

char *_getenv(char **env, char *name)
{
	int i = 0, len;

	len = _strlen(name);
	while (env[i])
	{
		if (_strncmp(name, env[i], len) == 0)
		{
			return (env[i]);
		}
		i++;
	}
	return NULL;
}

char **pathenv(char **env)
{
	char *str, *qtr, *delim = "=,:";
	char **ptr = NULL;
	unsigned int i = 0;

	str = _getenv(env, "PATH");
	qtr = strtok(str, delim);
	ptr = malloc(sizeof(char *) * (_strlen(str) * 8));
	if (!ptr)
	{
		return (NULL);
	}
	qtr = strtok(NULL, delim);
	while (qtr != NULL)
	{
		ptr[i] = strdup(qtr);
		i++;
		qtr = strtok(NULL, delim);
	}
	ptr[i] = '\0';
	return (ptr);
}
