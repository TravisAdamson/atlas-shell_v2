#ifndef _SH_H
#define _SH_H

#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_LEN 1024
#define OPS ";&|><"
#define SPC_DELIM " \t\n\r"

/**
 * struct prog_dt - stores data related to program runtime
 * @prog_name: retains program name (argv[0])
 * @env_lst: adjustable copy of environ
 * @env_lst_size: size of memory allocated for env_list
 * @env_size: size of environ upon launch
*/

typedef struct prog_dt
{
	char *prog_name;
	char **env_lst;
	size_t env_lst_size;
	size_t env_size;
} p_dt_t;

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

typedef struct comm_dt
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
} c_dt_t;

extern char **environ;
extern p_dt_t prog;
extern c_dt_t comm_data;
extern int error_flag_fix;

int __attribute__ ((constructor)) env_load(void);
void __attribute__ ((destructor)) env_free(void);

void handle_interrupt(int sig);

int shell_cracked(char *data);
ssize_t prompt(char *prompt_str, char **data, size_t *len);
int empty_data(char *data);
char *sep(char **data, char *delim);

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

int run_comm(c_lst_t *comms);

char *_getenv(char *var_name);

void free_strvec(char **strvec);

char **make_slash_comm(char **ps, char *comm);
char **remove_all_colons(char *c_string);
int fork_exe(char *name, c_lst_t *comm);
int fork_exe_w_pipe(char *name, c_lst_t *comm);
void free_comm_data(void);

int run_comm_branch(c_lst_t *comm);
int check_dirs(void);

int _isdigit(int chr);
int _atoi(char *input_string);

int builtin(char **comm);
void run_error(char **comm, int code);

int run_opp(c_lst_t *comm);
int colon_opp(c_lst_t *comm);
int pipes(c_lst_t *comm, int p_count);
int p_count(int *ops);
int right_redirect(c_lst_t *comm);
int right_redirect_2(c_lst_t *comm);
int left_redirect(c_lst_t *comm);
int left_redirect_2(c_lst_t *comm);

int p_string_mem(char *p_str, char *comm);
char **proc_path(char *comm);

#endif
