#include "kash.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 *
 * @ntr: memory to be reallocated
 * @size: new size, in bytes of the new memory block
 *
 * Return: pointer to the reallocated memory
 */

char **_realloc(char **ntr, int size)
{
	char **new_ptr = NULL;
	int i, j;

	/* allocate memory for new size */
	new_ptr = malloc(sizeof(char *) * size);
	if (new_ptr == NULL) /* if malloc fails */
	{
		free(new_ptr);
		exit(-1);
	}

	/* run loop to store array of strings */
	for (i = 0; ntr[i]; i++)
	{
		j = 0;
		new_ptr[j] = ntr[i];
	}

	free(ntr); /* free old array */
	return (new_ptr); /* return new array */
}

/**
 * _free - frees an array of strings
 *
 * @vector: array of strings
 *
 * Return: void
 */

void _free(char **vector)
{
	unsigned int i = 0;

	while (vector[i]) /* loop through array of strings */
	{
		free(vector[i]); /* free strings */
		i++;
	}
	free(vector); /* free array */
	vector = NULL;
}
