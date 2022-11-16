#include "kash.h"

/**
 * main - creates a shell
 *
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variables
 *
 * Return: (0), Success
 */

int main(int argc, char **argv, char **env)
{
	char *line;
	char **tokens;

	(void)argc; /* ignore argc */

	signal(SIGINT, sig_handler); /* handle signal */
	/* infinite loop that returns the prompt */
	while (1)
	{
		prompt(); /* display prompt */
		line = kash_read(); /* read input */
		tokens = kash_split(line); /* split input into array of strings */

		if (tokens[0] != NULL)
		{
			kash_exec(argv, env, tokens); /* execute the command */
		}

		free(tokens); /* free array of strings */
		free(line); /* free input string */
	}
	return (0);
}
