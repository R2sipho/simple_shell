#include "main.h"

/**
 * find_command - Find the full path of a command in the PATH environment variable
 * @command: The command to find
 * Return: The full path of the command if found, "Error: Not Found" otherwise
 */
char *find_command(char *command)
{
	DIR *folder;
	struct dirent *entry;
	char *cmd, comp, **str = malloc(sizeof(char) * 1024);
	char **split = malloc(sizeof(char) * 1024);
	int i;

	while (*environ != NULL)
	{
		if (!(_strcmpdir(*environ, "PATH")))
		{
			*str = *environ;
			for (i = 0; i < 9; i++, split++, str++)
			{
				*split = strtok(*str, ":='PATH'");
				folder = opendir(*split);
				if (folder == NULL)
				{
					perror("Unable to read directory");
				}
				while ((entry = readdir(folder)))
				{
					cmd = entry->d_name;
					comp = _strcmpdir(cmd, command);
					if (comp == 0)
					{
						return (*split);
					}
					if (cmd == NULL)
					{
						perror("Error");
					}
				}
			}
		}
		environ++;
	}
	return ("Error: Not Found");
}

