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
		 /* iterate through the first n bytes */
		if (i == (n - 1))
		{
			break;
		}
		i++;
	}
	return flag;
}

/**
 * _strdup - duplicates a string
 *
 * @s: string to be duplicated
 *
 * Return: pointer to the duplicated string
 */

char *_strdup(char *s)
{
	char *ptr = NULL;
	int i, len;

	len = _strlen(s); /* find length of string */
	/* allocate memory for string to be duplicated */
	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr) /* if malloc fails */
	{
		free(ptr);
		return (NULL);
	}
	/* loop to duplicate each character in the string */
	for (i = 0; s[i] != '\0'; i++)
	{
		ptr[i] = s[i];
	}
	ptr[i] = '\0'; /* null terminate the string */
	return (ptr); /* return duplicated string */
}

/**
 * _strcat - concatenates two strings
 *
 * @dest: second string
 * @src: first string
 *
 * Return: pointer to concatenated string
 */

char *_strcat(char *dest, char *src)
{
	char *str;
	int i, j;
	int len1, len2;

	if (dest == NULL)
		len1 = 0;
	else
		len1 = _strlen(dest);
	if (src == NULL)
		len2 = 0;
	else
		len2 = _strlen(src);

	str = malloc(sizeof(char) * (len1 + len2 + 2));
	if (str == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len1; i++)
	{
		str[i] = dest[i];
	}
	str[i] = '/';
	i++;
	for (j = 0; j < len2; j++, i++)
	{
		str[i] = src[j];
	}
	str[i] = '\0';
	free(dest);
	return (str);
}
