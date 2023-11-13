#include "main.h"

/**
 * main - Entry point of the program
 * @ac: Number of arguments
 * @av: Array of argument strings
 * Return: Always 0 (Success)
 */
int main(int ac, char **av)
{
	(void)av;
	(void)ac;

	signal(SIGINT, controlC);
	prompt();
	return (0);
}
