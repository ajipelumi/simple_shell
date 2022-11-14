#include "kash.h"

/**
 * _strlen - returns the length of a string
 *
 * @str: string to be scanned
 *
 * Return: string length
 */

int _strlen(char *str)
{
	int len;

	/* iterate through our string */
	for (len = 0; str[len] != '\0'; len++)
	{
		/* length increases */
	}
	return (len); /* rerturn length */
}

/**
 * _strcmp - compares two strings
 *
 * @s1: str on the left side
 * @s2: string on the right side
 *
 * Return: 0 if both strings are equal
 * 1 if s1 is greater than s2,
 * -1 if s2 is greater than s1
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int flag = 0;

	while (flag == 0)
	{
		/* if first string is greater */
		if (s1[i] > s2[i])
		{
			flag = 1; /* return 1 */
		}
		/* else if first string is less */
		else if (s1[i] < s2[i])
		{
			flag = -1; /* return -1 */
		}
		/* iterate through the first string */
		if (s1[i] == '\0')
		{
			break;
		}
		i++;
	}
	return flag;
}

/**
 * _strncmp - compares two strings
 *
 * @s1: str on the left side
 * @s2: string on the right side
 * @n: the first n bytes
 *
 * Return: 0 if both strings are equal
 * 1 if s1 is greater than s2,
 * -1 if s2 is greater than s1
 */

int _strncmp(char *s1, char *s2, size_t n)
{
	unsigned int i = 0;
	int flag = 0;

	while (flag == 0)
	{
		if (s1[i] > s2[i])
		{
			flag = 1;
		}
		else if (s1[i] < s2[i])
		{
			flag = -1;
		}
		if (i == (n - 1))
		{
			break;
		}
		i++;
	}
	return flag;
}
