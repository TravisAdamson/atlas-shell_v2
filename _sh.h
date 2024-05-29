#ifndef _SH_H
#define _SH_H

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

#define MAX_LEN 1024

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

typedef struct comm_lst
{
	char *cmd_name;
	char *comm[MAX_LEN];
	int cmd_ind;
	struct comm_lst *next;
	struct comm_lst *prev;
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
	struct command_list *comms;
} c_dt_t;

extern char **environ;
extern p_dt_t prog;
extern c_dt_t comm_data;

void handle_interrupt(int sig);

#endif
