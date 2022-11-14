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
	extern char ** environ;
	int i = 0, len;

	len = _strlen(name);
	while (environ[i])
	{
		if (_strncmp(name, environ[i], len) == 0)
		{
			return (environ[i]);
		}
		i++;
	}
	return NULL;
}
