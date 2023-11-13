#include "main.h"

/**
 * _strcmpdir - Compare two strings up to the first three characters
 * @s1: First string
 * @s2: Second string
 * Return: The difference between the ASCII values of the first differing characters
 */
int _strcmpdir(char *s1, char *s2)
{
	int i = 0;

	for (; (*s2 != '\0' && *s1 != '\0') && *s1 == *s2; s1++)
	{
		if (i == 3)
			break;
		i++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 * charput - Write a character to the standard output
 * @c: The character to be written
 * Return: The number of characters written
 */
int charput(char c)
{
	return write(1, &c, 1);
}

/**
 * place - Write a string to the standard output
 * @str: The string to be written
 */
void place(char *str)
{
	while (*str != '\0')
	{
		charput(*str);
		str++;
	}
}

/**
 * _strlen - Calculate the length of a string
 * @str: The input string
 * Return: The length of the string
 */
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;

	return i;
}

/**
 * str_concat - Concatenate two strings
 * @s1: The first string
 * @s2: The second string
 * Return: A newly allocated string containing the concatenated strings
 */
char *str_concat(char *s1, char *s2)
{
	char *a;
	int lens1, lens2, j, i, e;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	lens1 = _strlen(s1);
	lens2 = _strlen(s2);

	a = malloc((lens1 + lens2 + 1) * sizeof(char));

	if (a == NULL)
		return NULL;

	for (j = 0; j < lens1; j++)
	{
		a[j] = s1[j];
	}

	for (i = lens1, e = 0; e <= lens2; i++, e++)
	{
		a[i] = s2[e];
	}
	return a;
}

