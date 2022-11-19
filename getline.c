#include "kash.h"
#include <unistd.h>
#include <string.h>
/**
 * assign_lineptr - Reassigns the lineptr variable for _getline
 *
 * @lineptr: A buffer to store input variable
 *
 * @n: The size of lineptr
 *
 * @buffer: The string to assign to lineptr
 *
 * @b: The size of buffer
 */

void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b)
{
	if (*lineptr == NULL) /* making sure lineptr is empty */
	{
		if (b > 120)
			*n = b; /* assign the value of b to n*/
		else
			*n = 120; /* if not initialize n to 120 */
		*lineptr = buffer;
	}
	else if (*n < b)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else
	{
		strcpy(*lineptr, buffer);
		free(buffer);
	}
}

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t input;
	ssize_t ret;
	char c = 'x', *buffer;
	int r;

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * 120); /* assign memory to buffer */

	if (!buffer)
		return (-1);

	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (r == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= 120)
			buffer = realloc(buffer, input + 1);
		buffer[input] = c;
		input++;
	}
	buffer[input] = '\0';
	assign_lineptr(lineptr, n, buffer, input);

	ret = input;
	if (r != 0)
		input = 0;
	return (ret);
}
