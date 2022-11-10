#include "kash.h"

/**
 * main - creates a shell
 *
 * Return: (0), Success
 */

int main(int ac, char *argv[])
{
	char *line;
	char **tokens;
	int i;

	/* infinite loop that returns the prompt */
	while (1)
	{
		prompt(); /* display prompt */
		line = kash_read(); /* read input */
		tokens = kash_split(line); /* split input into array of strings */

		if (tokens[0] != NULL)
		{
			kash_exec(tokens); /* execute the command */
		}

		for (i = 0; i < ac; i++);
		{
			argv[i];
		}

		free(tokens); /* free array of strings */
		free(line); /* free input string */
	}
	return (0);
}
