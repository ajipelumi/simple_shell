#include "kash.h"

/**
 * main - creates a shell
 *
 * @ac: argument count
 * @av: argument vector
 * @env: environment variables
 *
 * Return: (0), Success
 */

int main(int ac, char **av, char **env)
{
	char *line;
	char **tokens;

	(void)ac; /* ignore ac */
	(void)av; /* ignore av */

	signal(SIGINT, sig_handler); /* handle signal */
	/* infinite loop that returns the prompt */
	while (1)
	{
		prompt(); /* display prompt */
		line = kash_read(); /* read input */
		tokens = kash_split(line); /* split input into array of strings */

		if (tokens[0] != NULL)
		{
			kash_exec(env, tokens); /* execute the command */
		}

		free(tokens); /* free array of strings */
		free(line); /* free input string */
	}
	return (0);
}
