#include "kash.h"

/**
 * main - creates a shell
 *
 * Return: (0), Success
 */

int main(void)
{
	char *line;
	char **tokens;

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

		free(tokens); /* free array of strings */
		free(line); /* free input string */
	}
	return (0);
}
