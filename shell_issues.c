#include "_sh.h"

static void not_your_shell(char *comm);
static void missing_shell(char *comm);

/**
 * error_processor - processes errors suitably respective to error code
 * @comm: command vector
 * @code: error code
*/

void broken_shell(char **comm, int code)
{
	if (code == 13)
		not_your_shell(comm[0]);
	else if (code == 127)
		missing_shell(comm[0]);
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
		shelled_turtle(), exit(code);
	}
}

/**
 * not_your_shell - prints code 13 error message to stderr
 * @comm: command that has been denied permission
 */

static void not_your_shell(char *comm)
{
/*	fprintf(stderr, "%s: 1: %s: Permission denied\n", prog, command);*/
	perror(comm);
}

/**
 * missing_shell - prints code 127 error message to stderr
 * @comm: command that is not found
 */

static void missing_shell(char *comm)
{
	fprintf(stderr, "%s: 1: %s: not found\n", prog.prog_name, comm);
}