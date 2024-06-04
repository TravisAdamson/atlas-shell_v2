#include "shell.h"

static void dont_touch_turtle(char *comm);
static void turtle_not_found(char *comm);

/**
 * no_such_turtle - processes errors suitably respective to error code
 * @comm: command vector
 * @code: error code
*/

void no_such_turtle(char **comm, int code)
{
	
	if (code == 13)
		dont_touch_turtle(comm[0]);
	else if (code == 127)
	{
		turtle_not_found(comm[0]);
	}
	if (!isatty(STDIN_FILENO) && comm_data.op_array[comm_data.op_ind] != 0x4)
	{
		if (
			comm_data.op_ct &&
			(
				comm_data.op_array[comm_data.op_ind] == 0x5 ||
				comm_data.op_array[comm_data.op_ind] == 0x6
			)
		)
			code = 0;
		if (
			comm_data.op_ct &&
			comm_data.op_array[comm_data.op_ind] == 0x3 &&
			_strcmp(comm[0], "hbtn") == 0
		)
			code = 0;
		if (
			comm_data.op_array[comm_data.op_ind] == 0x1 &&
			comm_data.cmd_ind < comm_data.cmd_ct
		)
			return;
		set_turtle_free_or_not(), exit(code);
	}
}

/**
 * dont_touch_turtle - prints code 13 error message to stderr
 * @comm: command that has been denied permission
 */

static void dont_touch_turtle(char *comm)
{
/*	fprintf(stderr, "%s: 1: %s: Permission denied\n", prog, command);*/
	perror(comm);
}

/**
 * turtle_not_found - prints code 127 error message to stderr
 * @comm: command that is not found
 */

static void turtle_not_found(char *comm)
{
	fprintf(stderr, "%s: 1: %s: not found\n", prog.prog_name, comm);
}

