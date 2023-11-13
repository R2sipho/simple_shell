#include "main.h"

/**
 * prompt - Display a prompt and read user input in a loop
 */
void prompt(void)
{
	for (;;)
	{
		char *text = NULL;
		pid_t child_pid;
		int status, lenbuf;
		size_t bufsize = 0;

		place("$ ");
		lenbuf = getline(&text, &bufsize, stdin);
		if (lenbuf == -1)
			exit(98);
		if (compareExit(text, "exit") == 0)
			exit(0);
		if (compareEnv(text, "env") == 0)
		{
			char **environ_copy = environ;
			while (*environ_copy != NULL)
			{
				if (!(_strcmpdir(*environ_copy, "USER")) ||
						!(_strcmpdir(*environ_copy, "LANGUAGE")) ||
						!(_strcmpdir(*environ_copy, "SESSION")) ||
						!(_strcmpdir(*environ_copy, "COMPIZ_CONFIG_PROFILE")) ||
						!(_strcmpdir(*environ_copy, "SHLV")) ||
						!(_strcmpdir(*environ_copy, "HOME")) ||
						!(_strcmpdir(*environ_copy, "C_IS")) ||
						!(_strcmpdir(*environ_copy, "DESKTOP_SESSION")) ||
						!(_strcmpdir(*environ_copy, "LOGNAME")) ||
						!(_strcmpdir(*environ_copy, "TERM")) ||
						!(_strcmpdir(*environ_copy, "PATH")))
				{
					place(*environ_copy);
					place("\n");
				}
				environ_copy++;
			}
		}
		child_pid = fork();
		if (child_pid < 0)
			perror("Error");
		if (child_pid == 0)
			identify_string(text);
		else
			wait(&status);
	}
}

