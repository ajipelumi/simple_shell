#include "kash.h"

/**
 * prompt - writes our shell prompt to standard output
 *
 * Return: void
 */

void prompt(void)
{
	char *s = "($) ";

	/* write to standard output */
	write(STDOUT_FILENO, s, 4);
}

/**
 * kash_read - read input from user
 *
 * Return: pointer to string that stores user input
 */

char *kash_read(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	/* reads standard input and stores as a string (line) */
	read = getline(&line, &len, stdin);
	if (read == -1) /* if it fails to read standard input */
	{
		perror("Error");
	}
	return (line); /* returns input as string */
}

/**
 * kash_split - split input into array of strings
 *
 * @line: string to be splitted
 *
 * Return: array of strings
 */

char **kash_split(char *line)
{
	char **tokens = NULL;
	char *tok;
	char *delim = " \t\r\n"; /* strtok splits string on instance of a delimiter */
	int len = 0, cap = 16;

	tokens = malloc(sizeof(char *) * cap);
	if (!tokens)
	{
		free(tokens);
		return (NULL);
	}
	tok = strtok(line, delim); /* split string to get the first token */
	/* run loop to check that token is not null */
	while (tok != NULL)
	{
		tokens[len] = tok; /* stores token in allocated memory */
		len++;
		/* if allocated memory is not enough to store tokens */
		if (len >= cap)
		{
			cap = (cap * 2);
			_realloc(tokens, cap); /* reallocates memory to store tokens */
		}

		tok = strtok(NULL, delim); /* fetches the next string until delimiter */
	}
	tokens[len] = NULL; /* null terminates array of strings */
	return (tokens); /* returns the array of strings */
}

/**
 * kash_exec - executes the command
 *
 * @av: argument vector
 *
 * Return: void
 */

void kash_exec(char **av)
{
	pid_t f;
	int exe, status;

	/* create child process */
	f = fork();
	if (f == 0) /* if child process is created */
	{
		/* execute command */
		exe = execve(av[0], av, NULL);
		if (exe == -1) /* if execve fails */
		{
			perror("Error");
		}
	}
	else if (f > 0) /* parent child receives process ID of child */
	{
		wait(&status); /* waits for child to return */
	}
	else /* child process was not created */
	{
		perror("Error");
	}
}
