
#ifndef _MAIN_H_
#define _MAIN_H_
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>

extern char **environ;

char *show_input(void);
void input_prompt(void);
char *_strcat(char *src);
int _strlen(char *str);
void place(char *str);
char *findfile(char *command);
char *find_command(char *command);
int compare(char *s1, char *s2);
int _strcmpdir(char *s1, char *s2);
int charput(char c);
void place(char *str);
char *str_concat(char *s1, char *s2);
int cherck_slash_sign(char *cmd);
int compareChar(char *s1, char *s2);
int compare_str(char *s1, char *s2);
void luanch_pro(char **cmd);
char **identify_string(char *parameter);
void control_signal(int sig);


#endif /* _MAIN_H_ */

