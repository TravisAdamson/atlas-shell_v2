#include "_sh.h"

static void error_perm(char *comm);
static void error_nf(char *comm);

/**
 * error_processor - processes errors suitably respective to error code
 * @comm: command vector
 * @code: error code
*/

void run_error(char **comm, int code)
{
	
	if (code == 13)
		error_perm(comm[0]);
	else if (code == 127)
	{
		error_nf(comm[0]);
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
			comm_data.op_array[comm_data.op_ind] == 0x1 &&
			comm_data.cmd_ind < comm_data.cmd_ct
		)
			return;
		free_comm_data(), exit(code);
	}
}

/**
 * error_perm - prints code 13 error message to stderr
 * @comm: command that has been denied permission
 */

static void error_perm(char *comm)
{
/*	fprintf(stderr, "%s: 1: %s: Permission denied\n", prog, command);*/
	perror(comm);
}

/**
 * error_nf - prints code 127 error message to stderr
 * @comm: command that is not found
 */

static void error_nf(char *comm)
{
	fprintf(stderr, "%s: 1: %s: not found\n", prog.prog_name, comm);
	error_flag_fix = 1;
}