#ifndef __SHELL_H__
#define __SHELL_H__

#define SPC_DELIM " \t\n\r"
#define PATH_DELIM ":"
#define MAX_LEN 1024

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

extern char **environ;

/**
 * struct builtIn - struct to assist in calling built-in functions
 * @command_name: built-in function name
 * @command_function: function called if input = command_name, NULL otherwise
 */

typedef struct builtIn
{
	char *command_name;
	int (*command_function)();
} builtIn;

int st;
void turtle_cross_road_or_not(char *input, char **argv);
int turtle_or_not(char *file);
void handle_turtle_interrupt(int sig);
void __attribute__ ((constructor)) coolIntro(void);
int empty_turtle_shell(char *input);
int change_working_directory(char *path);
int print_environment_variables(char **environment_variables);
void set_turtle_free_or_not(char **cmdS);
char *shell_cracked(char **input, char *delim);
ssize_t feed_the_turtle(const char *prmptStyle, char **input, size_t *len);
int turtle_surgery(char *input, char **cmdS, char *delim);

#endif
