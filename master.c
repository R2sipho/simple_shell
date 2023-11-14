#include "main.h"

/**
 * cherck_slash_sign - Check if a command includes a '/'
 * @cmd: The command to check
 * Return: 1 if '/' is found, 0 otherwise
 */
int cherck_slash_sign(char *cmd)
{
	int cont = 0;

	while (cmd[cont])
	{
		if (cmd[0] == '/')
		{
			printf("%c\n", cmd[0]);
			return (1);
		}

		cont++;
	}
	return (0);
}

/**
 * compareChar - Compare the first three characters of two strings
 * @s1: First string
 * @s2: Second string
 * Return: The difference between the ASCII values of the differing characters
 */
int compareChar(char *s1, char *s2)
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
 * compare_str - Compare the first two characters of two strings
 * @s1: First string
 * @s2: Second string
 * Return: The difference between the ASCII values of the differing characters
 */
int compare_str(char *s1, char *s2)
{
	int i = 0;

	for (; (*s2 != '\0' && *s1 != '\0') && *s1 == *s2; s1++)
	{
		if (i == 2)
			break;
		i++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 * identify_string - Tokenize a string and execute a process
 * @parameter: The input string to tokenize
 * Return: Array of tokens
 */
char **identify_string(char *parameter)
{
	char **buf = malloc(1024 * sizeof(char *));
	char *split;
	int i = 0;
	char *delim = " \t\n";

	split = strtok(parameter, delim);

	while (split != NULL)
	{
		buf[i] = split;
		i++;
		split = strtok(NULL, delim);
	}
	luanch_pro(buf);
	return (buf);
}

/**
 * control_signal - Handle the Ctrl+C signal
 * @sig: Signal number
 */
void control_signal(int sig)
{
	(void) sig;
	write(1, "\n$ ", 3);
}

