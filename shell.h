#ifndef __SHELL_H__
#define __SHELL_H__

#define SPC_DELIM " \t\n\r"
#define PATH_DELIM ":"
#define MAX_LEN 1024
#define OPS ";&|><"

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

/**
 * struct prog_data - stores data related to program runtime
 * @prog_name: retains program name (argv[0])
 * @env_lst: adjustable copy of environ
 * @env_lst_size: size of memory allocated for env_list
 * @env_size: size of environ upon launch
*/

typedef struct prog_data
{
	char *prog_name;
	char **env_lst;
	size_t env_lst_size;
	size_t env_size;
} p_data_t;

/**
 * struct comm_lst - node for storing command information, useful when
 *                   controls or redirects used in command input
 * @cmd_name: raw unprocessed string representing single command
 * @comm: single processed command vector
 * @cmd_ind: stores position in sequence of entered commands, starts at 1
 * @next: pointer to next element in list
 * @prev: pointer to previous element in list
*/

typedef struct c_lst
{
	char *cmd_name;
	char *comm[MAX_LEN];
	int cmd_ind;
	struct c_lst *next;
	struct c_lst *prev;
} c_lst_t;

/**
 * struct comm_dt - data bank for each command entered
 * @input: raw unprocessed command line input ending with line break
 * @cmd_ct: total number of commands detected in parsed input
 * @cmd_ind: index to keep track of which commands have already been done
 * @op_ct: total number of supported control/redirect operators detected
 * @op_array: sequence of detected control/redirect operators
 * @op_add: count to verify op added at each position
 * @op_ind: index to keep track of which operators have already been done
 * @pipe_fd: array of file descriptors for pipe
 * @comms: doubly-linked list containing commands in sequence as entered
*/

typedef struct comm_data
{
	char *input;
	int cmd_ct;
	int cmd_ind;
	int op_ct;
	int op_array[16];
	int op_add;
	int op_ind;
	int pipe_fd[2];
	struct c_lst *comms;
} c_data_t;

/**
 * struct builtIn - struct to assist in calling built-in functions
 * @command_name: built-in function name
 * @command_function: function called if input = command_name, NULL otherwise
 */

typedef struct builtIn
{
	char *command_name;
	int (*command_function)();
} builtIn_t;

extern char **environ;
extern p_data_t prog;
extern c_data_t comm_data;

int turtle_environment(char **comm);
int rehome_turtle(char *path);
int cd_assist(char *dest_dir, int *changed);
int view_nest(void);
int turtle_is_free(char *code, char **comm);
int change_nest(char *name, char *val);
int clear_nest(char *name);

int turtle_cross_road_or_not(c_lst_t *comms);
void handle_turtle_interrupt(int sig);
int empty_turtle_shell(char *input);
int turtle_surgery(char *data);
ssize_t feed_the_turtle(char *prmptStyle, char **input, size_t *len);
int __attribute__ ((constructor)) env_load(void);
void __attribute__ ((destructor)) env_free(void);
char *_strcat(char *dest, char *src);
int _strcmp(char *str1, char *str2);
int _strncmp(char *str1, char *str2, int end);
char *_strcpy(char *dest, char *src);
int _str_len(char *str);
char *_strdup(char *str);
char *_strsep(char **str, const char *delim);
size_t _strcspn(const char *str1, const char *str2);
char *str_concat(char *dest, char *src);

void *_calloc(unsigned int nmemb, unsigned int size);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *memory, size_t old_size, size_t new_size);

char *_getenv(char *var_name);
int _isdigit(int chr);
int _atoi(char *input_string);

char **find_mate(char **ps, char *comm);
char **clear_debris(char *c_string);
int turtle_does(c_lst_t *comm);
int find_nest(void);
char **turtles_nest(char *comm);
int turtle_eggs(char *p_string, char *comm);
void free_strvec(char **strvec);
void set_turtle_free_or_not(void);
char *baby_turtles(char **data, char *delim);
int make_turtlets(char *name, c_lst_t *comm);
int make_turtlet(char *name, c_lst_t *comm);
void no_such_turtle(char **comm, int code);
int turtle_nap(c_lst_t *comm);
int turtle_homing(c_lst_t *comm);
int current_length(int *ops);
int turtle_current(c_lst_t *comm, int p_counted);
int turn_right(c_lst_t *comm);
int right_uturn(c_lst_t *comm);
int turn_left(c_lst_t *comm);
int left_uturn(c_lst_t *comm);

#endif
